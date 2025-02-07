
#include <nlohmann/json.hpp>
#include "prover_client.hpp"
#include "prover_utils.hpp"

using namespace std;
using json = nlohmann::json;

ProverClient::ProverClient (Goldilocks &fr, const Config &config) :
    fr(fr),
    config(config)
{
    // Create channel
    std::shared_ptr<grpc_impl::Channel> channel = ::grpc::CreateChannel(config.proverClientHost + ":" + to_string(config.proverClientPort), grpc::InsecureChannelCredentials());

    // Create stub (i.e. client)
    stub = new zkprover::v1::ZKProverService::Stub(channel);
}

void ProverClient::runThread (void)
{
    pthread_create(&t, NULL, clientThread, this);
}

void ProverClient::waitForThread (void)
{
    pthread_join(t, NULL);
}

void ProverClient::GetStatus (void)
{
    ::grpc::ClientContext context;
    ::zkprover::v1::GetStatusRequest request;
    ::zkprover::v1::GetStatusResponse response;
    stub->GetStatus(&context, request, &response);
    cout << "ProverClient::GetStatus() got: " << response.DebugString() << endl;
}

string ProverClient::GenProof (void)
{
    if (config.inputFile.size() == 0)
    {
        cerr << "Error: ProverClient::GenProof() found config.inputFile empty" << endl;
        exit(-1);
    }
    ::grpc::ClientContext context;
    ::zkprover::v1::InputProver *pInputProver = new ::zkprover::v1::InputProver();
    Input input(fr);
    json inputJson;
    file2json(config.inputFile, inputJson);
    input.load(inputJson);
    input2InputProver(fr, input, *pInputProver);
    ::zkprover::v1::GenProofRequest request;
    request.set_allocated_input(pInputProver);
    ::zkprover::v1::GenProofResponse response;
    stub->GenProof(&context, request, &response);
    cout << "Client::GenProof() got: " << response.DebugString() << endl;
    return response.id();
}

bool ProverClient::GetProof (const string &uuid)
{
    if (uuid.size() == 0)
    {
        cerr << "Error: ProverClient::GetProof() called with uuid empty" << endl;
        exit(-1);
    }
    ::grpc::ClientContext context;
    ::zkprover::v1::GetProofRequest request;
    request.set_id(uuid);
    ::zkprover::v1::GetProofResponse response;
    //stub->GetProof(&context, request, &response);
    std::unique_ptr<grpc::ClientReaderWriter<zkprover::v1::GetProofRequest, zkprover::v1::GetProofResponse>> readerWriter;
    readerWriter = stub->GetProof(&context);
    readerWriter->Write(request);
    readerWriter->Read(&response);
    cout << "Client::GetProof() got: " << response.DebugString() << endl;
    if (response.result() == zkprover::v1::GetProofResponse_ResultGetProof_RESULT_GET_PROOF_PENDING)
    {
        return false;
    }
    return true;
}

bool ProverClient::Cancel (const string &uuid)
{
    if (uuid.size() == 0)
    {
        cerr << "Error: ProverClient::Cancel() called with uuid empty" << endl;
        exit(-1);
    }
    ::grpc::ClientContext context;
    ::zkprover::v1::CancelRequest request;
    request.set_id(uuid);
    ::zkprover::v1::CancelResponse response;
    stub->Cancel(&context, request, &response);
    cout << "Client::Cancel() got: " << response.DebugString() << endl;
    if (response.result() == zkprover::v1::CancelResponse_ResultCancel_RESULT_CANCEL_OK)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void* clientThread(void* arg)
{
    cout << "clientThread() started" << endl;
    string uuid;
    ProverClient *pClient = (ProverClient *)arg;
    sleep(2);

    // Get server status
    cout << "clientThread() calling GetStatus()" << endl;
    pClient->GetStatus();

    // Generate a proof, call get proof up to 100 times (x5sec) until completed
    cout << "clientThread() calling GenProof()" << endl;
    uuid = pClient->GenProof();
    uint64_t i = 0;
    for (i=0; i<200; i++)
    {
        sleep(5);
        if (pClient->GetProof(uuid)) break;
    }
    if (i == 100)
    {
        cerr << "Error: clientThread() GetProof() polling failed" << endl;
        exit(-1);
    }

    // Cancelling an alreay completed request should fail
    cout << "clientThread() calling Cancel()" << endl;
    if (pClient->Cancel(uuid))
    {
        cerr << "Error: clientThread() Cancel() of completed request did not fail" << endl;
        exit(-1);
    }
    
    return NULL;
}