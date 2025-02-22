#include "rom_line.hpp"

string RomLine::toString(Goldilocks &fr)
{
    string result;

    if (!fr.isZero(inA)) result += " inA=" + fr.toString(inA,10);
    if (!fr.isZero(inB)) result += " inB=" + fr.toString(inB,10);
    if (!fr.isZero(inC)) result += " inC=" + fr.toString(inC,10);
    if (!fr.isZero(inD)) result += " inD=" + fr.toString(inD,10);
    if (!fr.isZero(inE)) result += " inE=" + fr.toString(inE,10);
    if (!fr.isZero(inSR)) result += " inSR=" + fr.toString(inSR,10);
    if (!fr.isZero(inCTX)) result += " inCTX=" + fr.toString(inCTX,10);
    if (!fr.isZero(inSP)) result += " inSP=" + fr.toString(inSP,10);
    if (!fr.isZero(inPC)) result += " inPC=" + fr.toString(inPC,10);
    if (!fr.isZero(inGAS)) result += " inGAS=" + fr.toString(inGAS,10);
    if (!fr.isZero(inMAXMEM)) result += " inMAXMEM=" + fr.toString(inMAXMEM,10);
    if (!fr.isZero(inSTEP)) result += " inSTEP=" + fr.toString(inSTEP,10);
    if (!fr.isZero(inFREE)) result += " inFREE=" + fr.toString(inFREE,10);
    if (!fr.isZero(inRR)) result += " inRR=" + fr.toString(inRR,10);
    if (!fr.isZero(inHASHPOS)) result += " inHASHPOS=" + fr.toString(inHASHPOS,10);
    if (!fr.isZero(inCntArith)) result += " inCntArith=" + fr.toString(inCntArith,10);
    if (!fr.isZero(inCntBinary)) result += " inCntBinary=" + fr.toString(inCntBinary,10);
    if (!fr.isZero(inCntMemAlign)) result += " inCntMemAlign=" + fr.toString(inCntMemAlign,10);
    if (!fr.isZero(inCntKeccakF)) result += " inCntKeccakF=" + fr.toString(inCntKeccakF,10);
    if (!fr.isZero(inCntPoseidonG)) result += " inCntPoseidonG=" + fr.toString(inCntPoseidonG,10);
    if (!fr.isZero(inCntPaddingPG)) result += " inCntPaddingPG=" + fr.toString(inCntPaddingPG,10);
    if (!fr.isZero(inROTL_C)) result += " inROTL_C=" + fr.toString(inROTL_C,10);
    if (bConstPresent) result += " CONST=" + fr.toString(CONST,10);
    if (bConstLPresent) result += " CONSTL=" + CONSTL.get_str(16);
    if (mOp != 0) result += " mOp=" + to_string(mOp);
    if (mWR != 0) result += " mWR=" + to_string(mWR);
    if (hashK != 0) result += " hashK=" + to_string(hashK);
    if (hashKLen != 0) result += " hashKLen=" + to_string(hashKLen);
    if (hashKDigest != 0) result += " hashKDigest=" + to_string(hashKDigest);
    if (hashP != 0) result += " hashP=" + to_string(hashP);
    if (hashPLen != 0) result += " hashPLen=" + to_string(hashPLen);
    if (hashPDigest != 0) result += " hashPDigest=" + to_string(hashPDigest);
    if (JMP != 0) result += " JMP=" + to_string(JMP);
    if (JMPC != 0) result += " JMPC=" + to_string(JMPC);
    if (JMPN != 0) result += " JMPN=" + to_string(JMPN);
    if (bOffsetPresent) { result += " offset=" + to_string(offset); result += " offsetLabel=" + offsetLabel; }

    if (useCTX != 0) result += " useCTX=" + to_string(useCTX);
    if (isCode != 0) result += " isCode=" + to_string(isCode);
    if (isStack != 0) result += " isStack=" + to_string(isStack);
    if (isMem != 0) result += " isMem=" + to_string(isMem);
    if (incCode != 0) result += " incCode=" + to_string(incCode);
    if (incStack != 0) result += " incStack=" + to_string(incStack);
    if (ind != 0) result += " ind=" + to_string(ind);
    if (indRR != 0) result += " indRR=" + to_string(indRR);

    if (shl != 0) result += " shl=" + to_string(shl);
    if (shr != 0) result += " shr=" + to_string(shr);
    if (assert != 0) result += " assert=" + to_string(assert);

    if (setA != 0) result += " setA=" + to_string(setA);
    if (setB != 0) result += " setB=" + to_string(setB);
    if (setC != 0) result += " setC=" + to_string(setC);
    if (setD != 0) result += " setD=" + to_string(setD);
    if (setE != 0) result += " setE=" + to_string(setE);
    if (setSR != 0) result += " setSR=" + to_string(setSR);
    if (setCTX != 0) result += " setCTX=" + to_string(setCTX);
    if (setSP != 0) result += " setSP=" + to_string(setSP);
    if (setPC != 0) result += " setPC=" + to_string(setPC);
    if (setGAS != 0) result += " setGAS=" + to_string(setGAS);
    if (setMAXMEM != 0) result += " setMAXMEM=" + to_string(setMAXMEM);
    if (setRR != 0) result += " setRR=" + to_string(setRR);
    if (setHASHPOS != 0) result += " setHASHPOS=" + to_string(setHASHPOS);

    if (sRD != 0) result += " sRD=" + to_string(sRD);
    if (sWR != 0) result += " sWR=" + to_string(sWR);
    if (arith != 0) result += " arith=" + to_string(arith);
    if (arithEq0 != 0) result += " arithEq0=" + to_string(arithEq0);
    if (arithEq1 != 0) result += " arithEq1=" + to_string(arithEq1);
    if (arithEq2 != 0) result += " arithEq2=" + to_string(arithEq2);
    if (arithEq3 != 0) result += " arithEq3=" + to_string(arithEq3);
    if (bin != 0) result += " bin=" + to_string(bin);
    if (binOpcode != 0) result += " binOpcode=" + to_string(binOpcode);
    if (comparator != 0) result += " comparator=" + to_string(comparator);
    if (opcodeRomMap != 0) result += " opcodeRomMap=" + to_string(opcodeRomMap);
    if (memAlign != 0) result += " memAlign=" + to_string(memAlign);
    if (memAlignWR != 0) result += " memAlignWR=" + to_string(memAlignWR);
    if (memAlignWR8 != 0) result += " memAlignWR8=" + to_string(memAlignWR8);

    result += " freeInTag={" + freeInTag.toString() + " }";

    for (uint64_t i=0; i<cmdBefore.size(); i++)
    {
        result += " cmdBefore[" + to_string(i) + "]={" + cmdBefore[i]->toString() + " }";
    }

    for (uint64_t i=0; i<cmdAfter.size(); i++)
    {
        result += " cmdAfter[" + to_string(i) + "]={" + cmdAfter[i]->toString() + " }";
    }

    //result += " fileName=" + fileName;
    //result += " line=" + to_string(line);
    //result += " lineStr=" + lineStr;

    return result;
}