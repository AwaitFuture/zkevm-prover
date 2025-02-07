#ifndef STARK_HPP
#define STARK_HPP

#include "stark_info.hpp"
#include "sm/pols_generated/commit_pols.hpp"
#include "sm/pols_generated/constant_pols.hpp"
#include "proof.hpp"
#include "transcript.hpp"
#include "zhInv.hpp"
#include "merklehash_goldilocks.hpp"
#include "polinomial.hpp"
#include "ntt_goldilocks.hpp"
class Stark
{
    const Config &config;
    StarkInfo starkInfo;
    void *pConstPolsAddress;
    const ConstantPols *pConstPols;
    void *pConstPolsAddress2ns;
    const ConstantPols *pConstPols2ns;
    void *pConstTreeAddress;
    ZhInv zi;
    uint64_t numCommited;
    uint64_t N;
    uint64_t NExtended;
    NTT_Goldilocks ntt;
    Transcript transcript;

private:
    void calculateH1H2(Polinomial &h1, Polinomial &h2, Polinomial &fPol, Polinomial &tPol);

public:

    Polinomial x_n;
    Polinomial x_2ns;
    Polinomial challenges;


    Stark(const Config &config);
    ~Stark();

    /* Returns the size of all the polynomials: committed, constant, etc. */
    uint64_t getTotalPolsSize(void) { return starkInfo.mapTotalN * sizeof(Goldilocks::Element); }

    /* Returns the size of the committed polynomials */
    uint64_t getCommitPolsSize(void) { return starkInfo.mapOffsets.section[cm2_n] * sizeof(Goldilocks::Element); }

    /* Generates a proof from the address to all polynomials memory area, and the committed pols */
    void genProof(void *pAddress, CommitPols &cmPols, const PublicInputs &publicInputs, Proof &proof);
};

#endif