#ifndef COMMIT_POLS_HPP
#define COMMIT_POLS_HPP

#include <cstdint>
#include "goldilocks/goldilocks_base_field.hpp"
#include "zkassert.hpp"

class CommitPol
{
private:
    Goldilocks::Element * _pAddress;
    uint64_t _degree;
    uint64_t _index;
public:
    CommitPol(Goldilocks::Element * pAddress, uint64_t degree, uint64_t index) : _pAddress(pAddress), _degree(degree), _index(index) {};
    Goldilocks::Element & operator[](int i) { return _pAddress[i*636]; };
    Goldilocks::Element * operator=(Goldilocks::Element * pAddress) { _pAddress = pAddress; return _pAddress; };

    Goldilocks::Element * address (void) { return _pAddress; }
    uint64_t degree (void) { return _degree; }
    uint64_t index (void) { return _index; }
};

class Byte4CommitPols
{
public:
    CommitPol freeIN;
    CommitPol out;
private:
    void * _pAddress;
    uint64_t _degree;
public:

    Byte4CommitPols (void * pAddress, uint64_t degree) :
        freeIN((Goldilocks::Element *)((uint8_t *)pAddress + 0), degree, 0),
        out((Goldilocks::Element *)((uint8_t *)pAddress + 8), degree, 1),
        _pAddress(pAddress),
        _degree(degree) {};

    static uint64_t pilDegree (void) { return 2097152; }
    static uint64_t pilSize (void) { return 16; }
    static uint64_t numPols (void) { return 2; }

    void * address (void) { return _pAddress; }
    uint64_t degree (void) { return _degree; }
    uint64_t size (void) { return _degree*2*sizeof(Goldilocks::Element); }
};

class MemAlignCommitPols
{
public:
    CommitPol inM[2];
    CommitPol inV;
    CommitPol wr256;
    CommitPol wr8;
    CommitPol m0[8];
    CommitPol m1[8];
    CommitPol w0[8];
    CommitPol w1[8];
    CommitPol v[8];
    CommitPol selM1;
    CommitPol factorV[8];
    CommitPol offset;
private:
    void * _pAddress;
    uint64_t _degree;
public:

    MemAlignCommitPols (void * pAddress, uint64_t degree) :
        inM{
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 16), degree, 2),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 24), degree, 3)
        },
        inV((Goldilocks::Element *)((uint8_t *)pAddress + 32), degree, 4),
        wr256((Goldilocks::Element *)((uint8_t *)pAddress + 40), degree, 5),
        wr8((Goldilocks::Element *)((uint8_t *)pAddress + 48), degree, 6),
        m0{
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 56), degree, 7),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 64), degree, 8),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 72), degree, 9),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 80), degree, 10),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 88), degree, 11),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 96), degree, 12),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 104), degree, 13),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 112), degree, 14)
        },
        m1{
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 120), degree, 15),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 128), degree, 16),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 136), degree, 17),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 144), degree, 18),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 152), degree, 19),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 160), degree, 20),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 168), degree, 21),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 176), degree, 22)
        },
        w0{
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 184), degree, 23),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 192), degree, 24),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 200), degree, 25),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 208), degree, 26),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 216), degree, 27),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 224), degree, 28),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 232), degree, 29),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 240), degree, 30)
        },
        w1{
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 248), degree, 31),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 256), degree, 32),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 264), degree, 33),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 272), degree, 34),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 280), degree, 35),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 288), degree, 36),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 296), degree, 37),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 304), degree, 38)
        },
        v{
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 312), degree, 39),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 320), degree, 40),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 328), degree, 41),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 336), degree, 42),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 344), degree, 43),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 352), degree, 44),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 360), degree, 45),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 368), degree, 46)
        },
        selM1((Goldilocks::Element *)((uint8_t *)pAddress + 376), degree, 47),
        factorV{
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 384), degree, 48),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 392), degree, 49),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 400), degree, 50),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 408), degree, 51),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 416), degree, 52),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 424), degree, 53),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 432), degree, 54),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 440), degree, 55)
        },
        offset((Goldilocks::Element *)((uint8_t *)pAddress + 448), degree, 56),
        _pAddress(pAddress),
        _degree(degree) {};

    static uint64_t pilDegree (void) { return 2097152; }
    static uint64_t pilSize (void) { return 440; }
    static uint64_t numPols (void) { return 55; }

    void * address (void) { return _pAddress; }
    uint64_t degree (void) { return _degree; }
    uint64_t size (void) { return _degree*55*sizeof(Goldilocks::Element); }
};

class ArithCommitPols
{
public:
    CommitPol x1[16];
    CommitPol y1[16];
    CommitPol x2[16];
    CommitPol y2[16];
    CommitPol x3[16];
    CommitPol y3[16];
    CommitPol s[16];
    CommitPol q0[16];
    CommitPol q1[16];
    CommitPol q2[16];
    CommitPol selEq[4];
    CommitPol carryL[3];
    CommitPol carryH[3];
private:
    void * _pAddress;
    uint64_t _degree;
public:

    ArithCommitPols (void * pAddress, uint64_t degree) :
        x1{
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 456), degree, 57),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 464), degree, 58),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 472), degree, 59),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 480), degree, 60),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 488), degree, 61),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 496), degree, 62),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 504), degree, 63),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 512), degree, 64),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 520), degree, 65),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 528), degree, 66),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 536), degree, 67),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 544), degree, 68),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 552), degree, 69),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 560), degree, 70),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 568), degree, 71),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 576), degree, 72)
        },
        y1{
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 584), degree, 73),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 592), degree, 74),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 600), degree, 75),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 608), degree, 76),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 616), degree, 77),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 624), degree, 78),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 632), degree, 79),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 640), degree, 80),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 648), degree, 81),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 656), degree, 82),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 664), degree, 83),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 672), degree, 84),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 680), degree, 85),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 688), degree, 86),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 696), degree, 87),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 704), degree, 88)
        },
        x2{
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 712), degree, 89),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 720), degree, 90),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 728), degree, 91),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 736), degree, 92),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 744), degree, 93),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 752), degree, 94),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 760), degree, 95),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 768), degree, 96),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 776), degree, 97),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 784), degree, 98),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 792), degree, 99),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 800), degree, 100),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 808), degree, 101),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 816), degree, 102),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 824), degree, 103),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 832), degree, 104)
        },
        y2{
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 840), degree, 105),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 848), degree, 106),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 856), degree, 107),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 864), degree, 108),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 872), degree, 109),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 880), degree, 110),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 888), degree, 111),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 896), degree, 112),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 904), degree, 113),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 912), degree, 114),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 920), degree, 115),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 928), degree, 116),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 936), degree, 117),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 944), degree, 118),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 952), degree, 119),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 960), degree, 120)
        },
        x3{
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 968), degree, 121),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 976), degree, 122),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 984), degree, 123),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 992), degree, 124),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 1000), degree, 125),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 1008), degree, 126),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 1016), degree, 127),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 1024), degree, 128),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 1032), degree, 129),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 1040), degree, 130),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 1048), degree, 131),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 1056), degree, 132),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 1064), degree, 133),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 1072), degree, 134),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 1080), degree, 135),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 1088), degree, 136)
        },
        y3{
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 1096), degree, 137),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 1104), degree, 138),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 1112), degree, 139),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 1120), degree, 140),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 1128), degree, 141),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 1136), degree, 142),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 1144), degree, 143),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 1152), degree, 144),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 1160), degree, 145),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 1168), degree, 146),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 1176), degree, 147),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 1184), degree, 148),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 1192), degree, 149),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 1200), degree, 150),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 1208), degree, 151),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 1216), degree, 152)
        },
        s{
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 1224), degree, 153),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 1232), degree, 154),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 1240), degree, 155),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 1248), degree, 156),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 1256), degree, 157),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 1264), degree, 158),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 1272), degree, 159),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 1280), degree, 160),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 1288), degree, 161),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 1296), degree, 162),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 1304), degree, 163),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 1312), degree, 164),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 1320), degree, 165),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 1328), degree, 166),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 1336), degree, 167),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 1344), degree, 168)
        },
        q0{
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 1352), degree, 169),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 1360), degree, 170),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 1368), degree, 171),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 1376), degree, 172),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 1384), degree, 173),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 1392), degree, 174),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 1400), degree, 175),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 1408), degree, 176),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 1416), degree, 177),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 1424), degree, 178),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 1432), degree, 179),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 1440), degree, 180),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 1448), degree, 181),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 1456), degree, 182),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 1464), degree, 183),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 1472), degree, 184)
        },
        q1{
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 1480), degree, 185),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 1488), degree, 186),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 1496), degree, 187),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 1504), degree, 188),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 1512), degree, 189),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 1520), degree, 190),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 1528), degree, 191),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 1536), degree, 192),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 1544), degree, 193),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 1552), degree, 194),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 1560), degree, 195),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 1568), degree, 196),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 1576), degree, 197),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 1584), degree, 198),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 1592), degree, 199),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 1600), degree, 200)
        },
        q2{
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 1608), degree, 201),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 1616), degree, 202),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 1624), degree, 203),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 1632), degree, 204),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 1640), degree, 205),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 1648), degree, 206),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 1656), degree, 207),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 1664), degree, 208),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 1672), degree, 209),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 1680), degree, 210),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 1688), degree, 211),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 1696), degree, 212),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 1704), degree, 213),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 1712), degree, 214),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 1720), degree, 215),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 1728), degree, 216)
        },
        selEq{
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 1736), degree, 217),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 1744), degree, 218),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 1752), degree, 219),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 1760), degree, 220)
        },
        carryL{
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 1768), degree, 221),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 1776), degree, 222),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 1784), degree, 223)
        },
        carryH{
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 1792), degree, 224),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 1800), degree, 225),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 1808), degree, 226)
        },
        _pAddress(pAddress),
        _degree(degree) {};

    static uint64_t pilDegree (void) { return 2097152; }
    static uint64_t pilSize (void) { return 1360; }
    static uint64_t numPols (void) { return 170; }

    void * address (void) { return _pAddress; }
    uint64_t degree (void) { return _degree; }
    uint64_t size (void) { return _degree*170*sizeof(Goldilocks::Element); }
};

class BinaryCommitPols
{
public:
    CommitPol freeInA;
    CommitPol freeInB;
    CommitPol freeInC;
    CommitPol a0;
    CommitPol a1;
    CommitPol a2;
    CommitPol a3;
    CommitPol a4;
    CommitPol a5;
    CommitPol a6;
    CommitPol a7;
    CommitPol b0;
    CommitPol b1;
    CommitPol b2;
    CommitPol b3;
    CommitPol b4;
    CommitPol b5;
    CommitPol b6;
    CommitPol b7;
    CommitPol c0;
    CommitPol c1;
    CommitPol c2;
    CommitPol c3;
    CommitPol c4;
    CommitPol c5;
    CommitPol c6;
    CommitPol c7;
    CommitPol opcode;
    CommitPol cIn;
    CommitPol cOut;
    CommitPol lCout;
    CommitPol lOpcode;
    CommitPol last;
    CommitPol useCarry;
private:
    void * _pAddress;
    uint64_t _degree;
public:

    BinaryCommitPols (void * pAddress, uint64_t degree) :
        freeInA((Goldilocks::Element *)((uint8_t *)pAddress + 1816), degree, 227),
        freeInB((Goldilocks::Element *)((uint8_t *)pAddress + 1824), degree, 228),
        freeInC((Goldilocks::Element *)((uint8_t *)pAddress + 1832), degree, 229),
        a0((Goldilocks::Element *)((uint8_t *)pAddress + 1840), degree, 230),
        a1((Goldilocks::Element *)((uint8_t *)pAddress + 1848), degree, 231),
        a2((Goldilocks::Element *)((uint8_t *)pAddress + 1856), degree, 232),
        a3((Goldilocks::Element *)((uint8_t *)pAddress + 1864), degree, 233),
        a4((Goldilocks::Element *)((uint8_t *)pAddress + 1872), degree, 234),
        a5((Goldilocks::Element *)((uint8_t *)pAddress + 1880), degree, 235),
        a6((Goldilocks::Element *)((uint8_t *)pAddress + 1888), degree, 236),
        a7((Goldilocks::Element *)((uint8_t *)pAddress + 1896), degree, 237),
        b0((Goldilocks::Element *)((uint8_t *)pAddress + 1904), degree, 238),
        b1((Goldilocks::Element *)((uint8_t *)pAddress + 1912), degree, 239),
        b2((Goldilocks::Element *)((uint8_t *)pAddress + 1920), degree, 240),
        b3((Goldilocks::Element *)((uint8_t *)pAddress + 1928), degree, 241),
        b4((Goldilocks::Element *)((uint8_t *)pAddress + 1936), degree, 242),
        b5((Goldilocks::Element *)((uint8_t *)pAddress + 1944), degree, 243),
        b6((Goldilocks::Element *)((uint8_t *)pAddress + 1952), degree, 244),
        b7((Goldilocks::Element *)((uint8_t *)pAddress + 1960), degree, 245),
        c0((Goldilocks::Element *)((uint8_t *)pAddress + 1968), degree, 246),
        c1((Goldilocks::Element *)((uint8_t *)pAddress + 1976), degree, 247),
        c2((Goldilocks::Element *)((uint8_t *)pAddress + 1984), degree, 248),
        c3((Goldilocks::Element *)((uint8_t *)pAddress + 1992), degree, 249),
        c4((Goldilocks::Element *)((uint8_t *)pAddress + 2000), degree, 250),
        c5((Goldilocks::Element *)((uint8_t *)pAddress + 2008), degree, 251),
        c6((Goldilocks::Element *)((uint8_t *)pAddress + 2016), degree, 252),
        c7((Goldilocks::Element *)((uint8_t *)pAddress + 2024), degree, 253),
        opcode((Goldilocks::Element *)((uint8_t *)pAddress + 2032), degree, 254),
        cIn((Goldilocks::Element *)((uint8_t *)pAddress + 2040), degree, 255),
        cOut((Goldilocks::Element *)((uint8_t *)pAddress + 2048), degree, 256),
        lCout((Goldilocks::Element *)((uint8_t *)pAddress + 2056), degree, 257),
        lOpcode((Goldilocks::Element *)((uint8_t *)pAddress + 2064), degree, 258),
        last((Goldilocks::Element *)((uint8_t *)pAddress + 2072), degree, 259),
        useCarry((Goldilocks::Element *)((uint8_t *)pAddress + 2080), degree, 260),
        _pAddress(pAddress),
        _degree(degree) {};

    static uint64_t pilDegree (void) { return 2097152; }
    static uint64_t pilSize (void) { return 272; }
    static uint64_t numPols (void) { return 34; }

    void * address (void) { return _pAddress; }
    uint64_t degree (void) { return _degree; }
    uint64_t size (void) { return _degree*34*sizeof(Goldilocks::Element); }
};

class PoseidonGCommitPols
{
public:
    CommitPol in0;
    CommitPol in1;
    CommitPol in2;
    CommitPol in3;
    CommitPol in4;
    CommitPol in5;
    CommitPol in6;
    CommitPol in7;
    CommitPol hashType;
    CommitPol cap1;
    CommitPol cap2;
    CommitPol cap3;
    CommitPol hash0;
    CommitPol hash1;
    CommitPol hash2;
    CommitPol hash3;
private:
    void * _pAddress;
    uint64_t _degree;
public:

    PoseidonGCommitPols (void * pAddress, uint64_t degree) :
        in0((Goldilocks::Element *)((uint8_t *)pAddress + 2088), degree, 261),
        in1((Goldilocks::Element *)((uint8_t *)pAddress + 2096), degree, 262),
        in2((Goldilocks::Element *)((uint8_t *)pAddress + 2104), degree, 263),
        in3((Goldilocks::Element *)((uint8_t *)pAddress + 2112), degree, 264),
        in4((Goldilocks::Element *)((uint8_t *)pAddress + 2120), degree, 265),
        in5((Goldilocks::Element *)((uint8_t *)pAddress + 2128), degree, 266),
        in6((Goldilocks::Element *)((uint8_t *)pAddress + 2136), degree, 267),
        in7((Goldilocks::Element *)((uint8_t *)pAddress + 2144), degree, 268),
        hashType((Goldilocks::Element *)((uint8_t *)pAddress + 2152), degree, 269),
        cap1((Goldilocks::Element *)((uint8_t *)pAddress + 2160), degree, 270),
        cap2((Goldilocks::Element *)((uint8_t *)pAddress + 2168), degree, 271),
        cap3((Goldilocks::Element *)((uint8_t *)pAddress + 2176), degree, 272),
        hash0((Goldilocks::Element *)((uint8_t *)pAddress + 2184), degree, 273),
        hash1((Goldilocks::Element *)((uint8_t *)pAddress + 2192), degree, 274),
        hash2((Goldilocks::Element *)((uint8_t *)pAddress + 2200), degree, 275),
        hash3((Goldilocks::Element *)((uint8_t *)pAddress + 2208), degree, 276),
        _pAddress(pAddress),
        _degree(degree) {};

    static uint64_t pilDegree (void) { return 2097152; }
    static uint64_t pilSize (void) { return 128; }
    static uint64_t numPols (void) { return 16; }

    void * address (void) { return _pAddress; }
    uint64_t degree (void) { return _degree; }
    uint64_t size (void) { return _degree*16*sizeof(Goldilocks::Element); }
};

class PaddingPGCommitPols
{
public:
    CommitPol acc[8];
    CommitPol freeIn;
    CommitPol addr;
    CommitPol rem;
    CommitPol remInv;
    CommitPol spare;
    CommitPol firstHash;
    CommitPol curHash0;
    CommitPol curHash1;
    CommitPol curHash2;
    CommitPol curHash3;
    CommitPol prevHash0;
    CommitPol prevHash1;
    CommitPol prevHash2;
    CommitPol prevHash3;
    CommitPol incCounter;
    CommitPol len;
    CommitPol crOffset;
    CommitPol crLen;
    CommitPol crOffsetInv;
    CommitPol crF0;
    CommitPol crF1;
    CommitPol crF2;
    CommitPol crF3;
    CommitPol crF4;
    CommitPol crF5;
    CommitPol crF6;
    CommitPol crF7;
    CommitPol crV0;
    CommitPol crV1;
    CommitPol crV2;
    CommitPol crV3;
    CommitPol crV4;
    CommitPol crV5;
    CommitPol crV6;
    CommitPol crV7;
private:
    void * _pAddress;
    uint64_t _degree;
public:

    PaddingPGCommitPols (void * pAddress, uint64_t degree) :
        acc{
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 2216), degree, 277),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 2224), degree, 278),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 2232), degree, 279),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 2240), degree, 280),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 2248), degree, 281),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 2256), degree, 282),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 2264), degree, 283),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 2272), degree, 284)
        },
        freeIn((Goldilocks::Element *)((uint8_t *)pAddress + 2280), degree, 285),
        addr((Goldilocks::Element *)((uint8_t *)pAddress + 2288), degree, 286),
        rem((Goldilocks::Element *)((uint8_t *)pAddress + 2296), degree, 287),
        remInv((Goldilocks::Element *)((uint8_t *)pAddress + 2304), degree, 288),
        spare((Goldilocks::Element *)((uint8_t *)pAddress + 2312), degree, 289),
        firstHash((Goldilocks::Element *)((uint8_t *)pAddress + 2320), degree, 290),
        curHash0((Goldilocks::Element *)((uint8_t *)pAddress + 2328), degree, 291),
        curHash1((Goldilocks::Element *)((uint8_t *)pAddress + 2336), degree, 292),
        curHash2((Goldilocks::Element *)((uint8_t *)pAddress + 2344), degree, 293),
        curHash3((Goldilocks::Element *)((uint8_t *)pAddress + 2352), degree, 294),
        prevHash0((Goldilocks::Element *)((uint8_t *)pAddress + 2360), degree, 295),
        prevHash1((Goldilocks::Element *)((uint8_t *)pAddress + 2368), degree, 296),
        prevHash2((Goldilocks::Element *)((uint8_t *)pAddress + 2376), degree, 297),
        prevHash3((Goldilocks::Element *)((uint8_t *)pAddress + 2384), degree, 298),
        incCounter((Goldilocks::Element *)((uint8_t *)pAddress + 2392), degree, 299),
        len((Goldilocks::Element *)((uint8_t *)pAddress + 2400), degree, 300),
        crOffset((Goldilocks::Element *)((uint8_t *)pAddress + 2408), degree, 301),
        crLen((Goldilocks::Element *)((uint8_t *)pAddress + 2416), degree, 302),
        crOffsetInv((Goldilocks::Element *)((uint8_t *)pAddress + 2424), degree, 303),
        crF0((Goldilocks::Element *)((uint8_t *)pAddress + 2432), degree, 304),
        crF1((Goldilocks::Element *)((uint8_t *)pAddress + 2440), degree, 305),
        crF2((Goldilocks::Element *)((uint8_t *)pAddress + 2448), degree, 306),
        crF3((Goldilocks::Element *)((uint8_t *)pAddress + 2456), degree, 307),
        crF4((Goldilocks::Element *)((uint8_t *)pAddress + 2464), degree, 308),
        crF5((Goldilocks::Element *)((uint8_t *)pAddress + 2472), degree, 309),
        crF6((Goldilocks::Element *)((uint8_t *)pAddress + 2480), degree, 310),
        crF7((Goldilocks::Element *)((uint8_t *)pAddress + 2488), degree, 311),
        crV0((Goldilocks::Element *)((uint8_t *)pAddress + 2496), degree, 312),
        crV1((Goldilocks::Element *)((uint8_t *)pAddress + 2504), degree, 313),
        crV2((Goldilocks::Element *)((uint8_t *)pAddress + 2512), degree, 314),
        crV3((Goldilocks::Element *)((uint8_t *)pAddress + 2520), degree, 315),
        crV4((Goldilocks::Element *)((uint8_t *)pAddress + 2528), degree, 316),
        crV5((Goldilocks::Element *)((uint8_t *)pAddress + 2536), degree, 317),
        crV6((Goldilocks::Element *)((uint8_t *)pAddress + 2544), degree, 318),
        crV7((Goldilocks::Element *)((uint8_t *)pAddress + 2552), degree, 319),
        _pAddress(pAddress),
        _degree(degree) {};

    static uint64_t pilDegree (void) { return 2097152; }
    static uint64_t pilSize (void) { return 344; }
    static uint64_t numPols (void) { return 43; }

    void * address (void) { return _pAddress; }
    uint64_t degree (void) { return _degree; }
    uint64_t size (void) { return _degree*43*sizeof(Goldilocks::Element); }
};

class StorageCommitPols
{
public:
    CommitPol free0;
    CommitPol free1;
    CommitPol free2;
    CommitPol free3;
    CommitPol hashLeft0;
    CommitPol hashLeft1;
    CommitPol hashLeft2;
    CommitPol hashLeft3;
    CommitPol hashRight0;
    CommitPol hashRight1;
    CommitPol hashRight2;
    CommitPol hashRight3;
    CommitPol oldRoot0;
    CommitPol oldRoot1;
    CommitPol oldRoot2;
    CommitPol oldRoot3;
    CommitPol newRoot0;
    CommitPol newRoot1;
    CommitPol newRoot2;
    CommitPol newRoot3;
    CommitPol valueLow0;
    CommitPol valueLow1;
    CommitPol valueLow2;
    CommitPol valueLow3;
    CommitPol valueHigh0;
    CommitPol valueHigh1;
    CommitPol valueHigh2;
    CommitPol valueHigh3;
    CommitPol siblingValueHash0;
    CommitPol siblingValueHash1;
    CommitPol siblingValueHash2;
    CommitPol siblingValueHash3;
    CommitPol rkey0;
    CommitPol rkey1;
    CommitPol rkey2;
    CommitPol rkey3;
    CommitPol siblingRkey0;
    CommitPol siblingRkey1;
    CommitPol siblingRkey2;
    CommitPol siblingRkey3;
    CommitPol rkeyBit;
    CommitPol level0;
    CommitPol level1;
    CommitPol level2;
    CommitPol level3;
    CommitPol pc;
    CommitPol selOldRoot;
    CommitPol selNewRoot;
    CommitPol selValueLow;
    CommitPol selValueHigh;
    CommitPol selSiblingValueHash;
    CommitPol selRkey;
    CommitPol selRkeyBit;
    CommitPol selSiblingRkey;
    CommitPol selFree;
    CommitPol setHashLeft;
    CommitPol setHashRight;
    CommitPol setOldRoot;
    CommitPol setNewRoot;
    CommitPol setValueLow;
    CommitPol setValueHigh;
    CommitPol setSiblingValueHash;
    CommitPol setRkey;
    CommitPol setSiblingRkey;
    CommitPol setRkeyBit;
    CommitPol setLevel;
    CommitPol iHash;
    CommitPol iHashType;
    CommitPol iLatchSet;
    CommitPol iLatchGet;
    CommitPol iClimbRkey;
    CommitPol iClimbSiblingRkey;
    CommitPol iClimbSiblingRkeyN;
    CommitPol iRotateLevel;
    CommitPol iJmpz;
    CommitPol iJmp;
    CommitPol iConst0;
    CommitPol iConst1;
    CommitPol iConst2;
    CommitPol iConst3;
    CommitPol iAddress;
    CommitPol incCounter;
    CommitPol op0inv;
private:
    void * _pAddress;
    uint64_t _degree;
public:

    StorageCommitPols (void * pAddress, uint64_t degree) :
        free0((Goldilocks::Element *)((uint8_t *)pAddress + 2560), degree, 320),
        free1((Goldilocks::Element *)((uint8_t *)pAddress + 2568), degree, 321),
        free2((Goldilocks::Element *)((uint8_t *)pAddress + 2576), degree, 322),
        free3((Goldilocks::Element *)((uint8_t *)pAddress + 2584), degree, 323),
        hashLeft0((Goldilocks::Element *)((uint8_t *)pAddress + 2592), degree, 324),
        hashLeft1((Goldilocks::Element *)((uint8_t *)pAddress + 2600), degree, 325),
        hashLeft2((Goldilocks::Element *)((uint8_t *)pAddress + 2608), degree, 326),
        hashLeft3((Goldilocks::Element *)((uint8_t *)pAddress + 2616), degree, 327),
        hashRight0((Goldilocks::Element *)((uint8_t *)pAddress + 2624), degree, 328),
        hashRight1((Goldilocks::Element *)((uint8_t *)pAddress + 2632), degree, 329),
        hashRight2((Goldilocks::Element *)((uint8_t *)pAddress + 2640), degree, 330),
        hashRight3((Goldilocks::Element *)((uint8_t *)pAddress + 2648), degree, 331),
        oldRoot0((Goldilocks::Element *)((uint8_t *)pAddress + 2656), degree, 332),
        oldRoot1((Goldilocks::Element *)((uint8_t *)pAddress + 2664), degree, 333),
        oldRoot2((Goldilocks::Element *)((uint8_t *)pAddress + 2672), degree, 334),
        oldRoot3((Goldilocks::Element *)((uint8_t *)pAddress + 2680), degree, 335),
        newRoot0((Goldilocks::Element *)((uint8_t *)pAddress + 2688), degree, 336),
        newRoot1((Goldilocks::Element *)((uint8_t *)pAddress + 2696), degree, 337),
        newRoot2((Goldilocks::Element *)((uint8_t *)pAddress + 2704), degree, 338),
        newRoot3((Goldilocks::Element *)((uint8_t *)pAddress + 2712), degree, 339),
        valueLow0((Goldilocks::Element *)((uint8_t *)pAddress + 2720), degree, 340),
        valueLow1((Goldilocks::Element *)((uint8_t *)pAddress + 2728), degree, 341),
        valueLow2((Goldilocks::Element *)((uint8_t *)pAddress + 2736), degree, 342),
        valueLow3((Goldilocks::Element *)((uint8_t *)pAddress + 2744), degree, 343),
        valueHigh0((Goldilocks::Element *)((uint8_t *)pAddress + 2752), degree, 344),
        valueHigh1((Goldilocks::Element *)((uint8_t *)pAddress + 2760), degree, 345),
        valueHigh2((Goldilocks::Element *)((uint8_t *)pAddress + 2768), degree, 346),
        valueHigh3((Goldilocks::Element *)((uint8_t *)pAddress + 2776), degree, 347),
        siblingValueHash0((Goldilocks::Element *)((uint8_t *)pAddress + 2784), degree, 348),
        siblingValueHash1((Goldilocks::Element *)((uint8_t *)pAddress + 2792), degree, 349),
        siblingValueHash2((Goldilocks::Element *)((uint8_t *)pAddress + 2800), degree, 350),
        siblingValueHash3((Goldilocks::Element *)((uint8_t *)pAddress + 2808), degree, 351),
        rkey0((Goldilocks::Element *)((uint8_t *)pAddress + 2816), degree, 352),
        rkey1((Goldilocks::Element *)((uint8_t *)pAddress + 2824), degree, 353),
        rkey2((Goldilocks::Element *)((uint8_t *)pAddress + 2832), degree, 354),
        rkey3((Goldilocks::Element *)((uint8_t *)pAddress + 2840), degree, 355),
        siblingRkey0((Goldilocks::Element *)((uint8_t *)pAddress + 2848), degree, 356),
        siblingRkey1((Goldilocks::Element *)((uint8_t *)pAddress + 2856), degree, 357),
        siblingRkey2((Goldilocks::Element *)((uint8_t *)pAddress + 2864), degree, 358),
        siblingRkey3((Goldilocks::Element *)((uint8_t *)pAddress + 2872), degree, 359),
        rkeyBit((Goldilocks::Element *)((uint8_t *)pAddress + 2880), degree, 360),
        level0((Goldilocks::Element *)((uint8_t *)pAddress + 2888), degree, 361),
        level1((Goldilocks::Element *)((uint8_t *)pAddress + 2896), degree, 362),
        level2((Goldilocks::Element *)((uint8_t *)pAddress + 2904), degree, 363),
        level3((Goldilocks::Element *)((uint8_t *)pAddress + 2912), degree, 364),
        pc((Goldilocks::Element *)((uint8_t *)pAddress + 2920), degree, 365),
        selOldRoot((Goldilocks::Element *)((uint8_t *)pAddress + 2928), degree, 366),
        selNewRoot((Goldilocks::Element *)((uint8_t *)pAddress + 2936), degree, 367),
        selValueLow((Goldilocks::Element *)((uint8_t *)pAddress + 2944), degree, 368),
        selValueHigh((Goldilocks::Element *)((uint8_t *)pAddress + 2952), degree, 369),
        selSiblingValueHash((Goldilocks::Element *)((uint8_t *)pAddress + 2960), degree, 370),
        selRkey((Goldilocks::Element *)((uint8_t *)pAddress + 2968), degree, 371),
        selRkeyBit((Goldilocks::Element *)((uint8_t *)pAddress + 2976), degree, 372),
        selSiblingRkey((Goldilocks::Element *)((uint8_t *)pAddress + 2984), degree, 373),
        selFree((Goldilocks::Element *)((uint8_t *)pAddress + 2992), degree, 374),
        setHashLeft((Goldilocks::Element *)((uint8_t *)pAddress + 3000), degree, 375),
        setHashRight((Goldilocks::Element *)((uint8_t *)pAddress + 3008), degree, 376),
        setOldRoot((Goldilocks::Element *)((uint8_t *)pAddress + 3016), degree, 377),
        setNewRoot((Goldilocks::Element *)((uint8_t *)pAddress + 3024), degree, 378),
        setValueLow((Goldilocks::Element *)((uint8_t *)pAddress + 3032), degree, 379),
        setValueHigh((Goldilocks::Element *)((uint8_t *)pAddress + 3040), degree, 380),
        setSiblingValueHash((Goldilocks::Element *)((uint8_t *)pAddress + 3048), degree, 381),
        setRkey((Goldilocks::Element *)((uint8_t *)pAddress + 3056), degree, 382),
        setSiblingRkey((Goldilocks::Element *)((uint8_t *)pAddress + 3064), degree, 383),
        setRkeyBit((Goldilocks::Element *)((uint8_t *)pAddress + 3072), degree, 384),
        setLevel((Goldilocks::Element *)((uint8_t *)pAddress + 3080), degree, 385),
        iHash((Goldilocks::Element *)((uint8_t *)pAddress + 3088), degree, 386),
        iHashType((Goldilocks::Element *)((uint8_t *)pAddress + 3096), degree, 387),
        iLatchSet((Goldilocks::Element *)((uint8_t *)pAddress + 3104), degree, 388),
        iLatchGet((Goldilocks::Element *)((uint8_t *)pAddress + 3112), degree, 389),
        iClimbRkey((Goldilocks::Element *)((uint8_t *)pAddress + 3120), degree, 390),
        iClimbSiblingRkey((Goldilocks::Element *)((uint8_t *)pAddress + 3128), degree, 391),
        iClimbSiblingRkeyN((Goldilocks::Element *)((uint8_t *)pAddress + 3136), degree, 392),
        iRotateLevel((Goldilocks::Element *)((uint8_t *)pAddress + 3144), degree, 393),
        iJmpz((Goldilocks::Element *)((uint8_t *)pAddress + 3152), degree, 394),
        iJmp((Goldilocks::Element *)((uint8_t *)pAddress + 3160), degree, 395),
        iConst0((Goldilocks::Element *)((uint8_t *)pAddress + 3168), degree, 396),
        iConst1((Goldilocks::Element *)((uint8_t *)pAddress + 3176), degree, 397),
        iConst2((Goldilocks::Element *)((uint8_t *)pAddress + 3184), degree, 398),
        iConst3((Goldilocks::Element *)((uint8_t *)pAddress + 3192), degree, 399),
        iAddress((Goldilocks::Element *)((uint8_t *)pAddress + 3200), degree, 400),
        incCounter((Goldilocks::Element *)((uint8_t *)pAddress + 3208), degree, 401),
        op0inv((Goldilocks::Element *)((uint8_t *)pAddress + 3216), degree, 402),
        _pAddress(pAddress),
        _degree(degree) {};

    static uint64_t pilDegree (void) { return 2097152; }
    static uint64_t pilSize (void) { return 664; }
    static uint64_t numPols (void) { return 83; }

    void * address (void) { return _pAddress; }
    uint64_t degree (void) { return _degree; }
    uint64_t size (void) { return _degree*83*sizeof(Goldilocks::Element); }
};

class NormGate9CommitPols
{
public:
    CommitPol freeA;
    CommitPol freeB;
    CommitPol gateType;
    CommitPol freeANorm;
    CommitPol freeBNorm;
    CommitPol freeCNorm;
    CommitPol a;
    CommitPol b;
    CommitPol c;
private:
    void * _pAddress;
    uint64_t _degree;
public:

    NormGate9CommitPols (void * pAddress, uint64_t degree) :
        freeA((Goldilocks::Element *)((uint8_t *)pAddress + 3224), degree, 403),
        freeB((Goldilocks::Element *)((uint8_t *)pAddress + 3232), degree, 404),
        gateType((Goldilocks::Element *)((uint8_t *)pAddress + 3240), degree, 405),
        freeANorm((Goldilocks::Element *)((uint8_t *)pAddress + 3248), degree, 406),
        freeBNorm((Goldilocks::Element *)((uint8_t *)pAddress + 3256), degree, 407),
        freeCNorm((Goldilocks::Element *)((uint8_t *)pAddress + 3264), degree, 408),
        a((Goldilocks::Element *)((uint8_t *)pAddress + 3272), degree, 409),
        b((Goldilocks::Element *)((uint8_t *)pAddress + 3280), degree, 410),
        c((Goldilocks::Element *)((uint8_t *)pAddress + 3288), degree, 411),
        _pAddress(pAddress),
        _degree(degree) {};

    static uint64_t pilDegree (void) { return 2097152; }
    static uint64_t pilSize (void) { return 72; }
    static uint64_t numPols (void) { return 9; }

    void * address (void) { return _pAddress; }
    uint64_t degree (void) { return _degree; }
    uint64_t size (void) { return _degree*9*sizeof(Goldilocks::Element); }
};

class KeccakFCommitPols
{
public:
    CommitPol a;
    CommitPol b;
    CommitPol c;
private:
    void * _pAddress;
    uint64_t _degree;
public:

    KeccakFCommitPols (void * pAddress, uint64_t degree) :
        a((Goldilocks::Element *)((uint8_t *)pAddress + 3296), degree, 412),
        b((Goldilocks::Element *)((uint8_t *)pAddress + 3304), degree, 413),
        c((Goldilocks::Element *)((uint8_t *)pAddress + 3312), degree, 414),
        _pAddress(pAddress),
        _degree(degree) {};

    static uint64_t pilDegree (void) { return 2097152; }
    static uint64_t pilSize (void) { return 24; }
    static uint64_t numPols (void) { return 3; }

    void * address (void) { return _pAddress; }
    uint64_t degree (void) { return _degree; }
    uint64_t size (void) { return _degree*3*sizeof(Goldilocks::Element); }
};

class Nine2OneCommitPols
{
public:
    CommitPol bit;
    CommitPol field9;
private:
    void * _pAddress;
    uint64_t _degree;
public:

    Nine2OneCommitPols (void * pAddress, uint64_t degree) :
        bit((Goldilocks::Element *)((uint8_t *)pAddress + 3320), degree, 415),
        field9((Goldilocks::Element *)((uint8_t *)pAddress + 3328), degree, 416),
        _pAddress(pAddress),
        _degree(degree) {};

    static uint64_t pilDegree (void) { return 2097152; }
    static uint64_t pilSize (void) { return 16; }
    static uint64_t numPols (void) { return 2; }

    void * address (void) { return _pAddress; }
    uint64_t degree (void) { return _degree; }
    uint64_t size (void) { return _degree*2*sizeof(Goldilocks::Element); }
};

class PaddingKKBitCommitPols
{
public:
    CommitPol rBit;
    CommitPol sOutBit;
    CommitPol r8;
    CommitPol connected;
    CommitPol sOut0;
    CommitPol sOut1;
    CommitPol sOut2;
    CommitPol sOut3;
    CommitPol sOut4;
    CommitPol sOut5;
    CommitPol sOut6;
    CommitPol sOut7;
private:
    void * _pAddress;
    uint64_t _degree;
public:

    PaddingKKBitCommitPols (void * pAddress, uint64_t degree) :
        rBit((Goldilocks::Element *)((uint8_t *)pAddress + 3336), degree, 417),
        sOutBit((Goldilocks::Element *)((uint8_t *)pAddress + 3344), degree, 418),
        r8((Goldilocks::Element *)((uint8_t *)pAddress + 3352), degree, 419),
        connected((Goldilocks::Element *)((uint8_t *)pAddress + 3360), degree, 420),
        sOut0((Goldilocks::Element *)((uint8_t *)pAddress + 3368), degree, 421),
        sOut1((Goldilocks::Element *)((uint8_t *)pAddress + 3376), degree, 422),
        sOut2((Goldilocks::Element *)((uint8_t *)pAddress + 3384), degree, 423),
        sOut3((Goldilocks::Element *)((uint8_t *)pAddress + 3392), degree, 424),
        sOut4((Goldilocks::Element *)((uint8_t *)pAddress + 3400), degree, 425),
        sOut5((Goldilocks::Element *)((uint8_t *)pAddress + 3408), degree, 426),
        sOut6((Goldilocks::Element *)((uint8_t *)pAddress + 3416), degree, 427),
        sOut7((Goldilocks::Element *)((uint8_t *)pAddress + 3424), degree, 428),
        _pAddress(pAddress),
        _degree(degree) {};

    static uint64_t pilDegree (void) { return 2097152; }
    static uint64_t pilSize (void) { return 96; }
    static uint64_t numPols (void) { return 12; }

    void * address (void) { return _pAddress; }
    uint64_t degree (void) { return _degree; }
    uint64_t size (void) { return _degree*12*sizeof(Goldilocks::Element); }
};

class PaddingKKCommitPols
{
public:
    CommitPol freeIn;
    CommitPol connected;
    CommitPol addr;
    CommitPol rem;
    CommitPol remInv;
    CommitPol spare;
    CommitPol firstHash;
    CommitPol len;
    CommitPol hash0;
    CommitPol hash1;
    CommitPol hash2;
    CommitPol hash3;
    CommitPol hash4;
    CommitPol hash5;
    CommitPol hash6;
    CommitPol hash7;
    CommitPol incCounter;
    CommitPol crOffset;
    CommitPol crLen;
    CommitPol crOffsetInv;
    CommitPol crF0;
    CommitPol crF1;
    CommitPol crF2;
    CommitPol crF3;
    CommitPol crF4;
    CommitPol crF5;
    CommitPol crF6;
    CommitPol crF7;
    CommitPol crV0;
    CommitPol crV1;
    CommitPol crV2;
    CommitPol crV3;
    CommitPol crV4;
    CommitPol crV5;
    CommitPol crV6;
    CommitPol crV7;
private:
    void * _pAddress;
    uint64_t _degree;
public:

    PaddingKKCommitPols (void * pAddress, uint64_t degree) :
        freeIn((Goldilocks::Element *)((uint8_t *)pAddress + 3432), degree, 429),
        connected((Goldilocks::Element *)((uint8_t *)pAddress + 3440), degree, 430),
        addr((Goldilocks::Element *)((uint8_t *)pAddress + 3448), degree, 431),
        rem((Goldilocks::Element *)((uint8_t *)pAddress + 3456), degree, 432),
        remInv((Goldilocks::Element *)((uint8_t *)pAddress + 3464), degree, 433),
        spare((Goldilocks::Element *)((uint8_t *)pAddress + 3472), degree, 434),
        firstHash((Goldilocks::Element *)((uint8_t *)pAddress + 3480), degree, 435),
        len((Goldilocks::Element *)((uint8_t *)pAddress + 3488), degree, 436),
        hash0((Goldilocks::Element *)((uint8_t *)pAddress + 3496), degree, 437),
        hash1((Goldilocks::Element *)((uint8_t *)pAddress + 3504), degree, 438),
        hash2((Goldilocks::Element *)((uint8_t *)pAddress + 3512), degree, 439),
        hash3((Goldilocks::Element *)((uint8_t *)pAddress + 3520), degree, 440),
        hash4((Goldilocks::Element *)((uint8_t *)pAddress + 3528), degree, 441),
        hash5((Goldilocks::Element *)((uint8_t *)pAddress + 3536), degree, 442),
        hash6((Goldilocks::Element *)((uint8_t *)pAddress + 3544), degree, 443),
        hash7((Goldilocks::Element *)((uint8_t *)pAddress + 3552), degree, 444),
        incCounter((Goldilocks::Element *)((uint8_t *)pAddress + 3560), degree, 445),
        crOffset((Goldilocks::Element *)((uint8_t *)pAddress + 3568), degree, 446),
        crLen((Goldilocks::Element *)((uint8_t *)pAddress + 3576), degree, 447),
        crOffsetInv((Goldilocks::Element *)((uint8_t *)pAddress + 3584), degree, 448),
        crF0((Goldilocks::Element *)((uint8_t *)pAddress + 3592), degree, 449),
        crF1((Goldilocks::Element *)((uint8_t *)pAddress + 3600), degree, 450),
        crF2((Goldilocks::Element *)((uint8_t *)pAddress + 3608), degree, 451),
        crF3((Goldilocks::Element *)((uint8_t *)pAddress + 3616), degree, 452),
        crF4((Goldilocks::Element *)((uint8_t *)pAddress + 3624), degree, 453),
        crF5((Goldilocks::Element *)((uint8_t *)pAddress + 3632), degree, 454),
        crF6((Goldilocks::Element *)((uint8_t *)pAddress + 3640), degree, 455),
        crF7((Goldilocks::Element *)((uint8_t *)pAddress + 3648), degree, 456),
        crV0((Goldilocks::Element *)((uint8_t *)pAddress + 3656), degree, 457),
        crV1((Goldilocks::Element *)((uint8_t *)pAddress + 3664), degree, 458),
        crV2((Goldilocks::Element *)((uint8_t *)pAddress + 3672), degree, 459),
        crV3((Goldilocks::Element *)((uint8_t *)pAddress + 3680), degree, 460),
        crV4((Goldilocks::Element *)((uint8_t *)pAddress + 3688), degree, 461),
        crV5((Goldilocks::Element *)((uint8_t *)pAddress + 3696), degree, 462),
        crV6((Goldilocks::Element *)((uint8_t *)pAddress + 3704), degree, 463),
        crV7((Goldilocks::Element *)((uint8_t *)pAddress + 3712), degree, 464),
        _pAddress(pAddress),
        _degree(degree) {};

    static uint64_t pilDegree (void) { return 2097152; }
    static uint64_t pilSize (void) { return 288; }
    static uint64_t numPols (void) { return 36; }

    void * address (void) { return _pAddress; }
    uint64_t degree (void) { return _degree; }
    uint64_t size (void) { return _degree*36*sizeof(Goldilocks::Element); }
};

class MemCommitPols
{
public:
    CommitPol addr;
    CommitPol step;
    CommitPol mOp;
    CommitPol mWr;
    CommitPol val[8];
    CommitPol lastAccess;
private:
    void * _pAddress;
    uint64_t _degree;
public:

    MemCommitPols (void * pAddress, uint64_t degree) :
        addr((Goldilocks::Element *)((uint8_t *)pAddress + 3720), degree, 465),
        step((Goldilocks::Element *)((uint8_t *)pAddress + 3728), degree, 466),
        mOp((Goldilocks::Element *)((uint8_t *)pAddress + 3736), degree, 467),
        mWr((Goldilocks::Element *)((uint8_t *)pAddress + 3744), degree, 468),
        val{
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 3752), degree, 469),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 3760), degree, 470),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 3768), degree, 471),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 3776), degree, 472),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 3784), degree, 473),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 3792), degree, 474),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 3800), degree, 475),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 3808), degree, 476)
        },
        lastAccess((Goldilocks::Element *)((uint8_t *)pAddress + 3816), degree, 477),
        _pAddress(pAddress),
        _degree(degree) {};

    static uint64_t pilDegree (void) { return 2097152; }
    static uint64_t pilSize (void) { return 104; }
    static uint64_t numPols (void) { return 13; }

    void * address (void) { return _pAddress; }
    uint64_t degree (void) { return _degree; }
    uint64_t size (void) { return _degree*13*sizeof(Goldilocks::Element); }
};

class MainCommitPols
{
public:
    CommitPol A7;
    CommitPol A6;
    CommitPol A5;
    CommitPol A4;
    CommitPol A3;
    CommitPol A2;
    CommitPol A1;
    CommitPol A0;
    CommitPol B7;
    CommitPol B6;
    CommitPol B5;
    CommitPol B4;
    CommitPol B3;
    CommitPol B2;
    CommitPol B1;
    CommitPol B0;
    CommitPol C7;
    CommitPol C6;
    CommitPol C5;
    CommitPol C4;
    CommitPol C3;
    CommitPol C2;
    CommitPol C1;
    CommitPol C0;
    CommitPol D7;
    CommitPol D6;
    CommitPol D5;
    CommitPol D4;
    CommitPol D3;
    CommitPol D2;
    CommitPol D1;
    CommitPol D0;
    CommitPol E7;
    CommitPol E6;
    CommitPol E5;
    CommitPol E4;
    CommitPol E3;
    CommitPol E2;
    CommitPol E1;
    CommitPol E0;
    CommitPol SR7;
    CommitPol SR6;
    CommitPol SR5;
    CommitPol SR4;
    CommitPol SR3;
    CommitPol SR2;
    CommitPol SR1;
    CommitPol SR0;
    CommitPol CTX;
    CommitPol SP;
    CommitPol PC;
    CommitPol GAS;
    CommitPol MAXMEM;
    CommitPol zkPC;
    CommitPol RR;
    CommitPol HASHPOS;
    CommitPol CONST7;
    CommitPol CONST6;
    CommitPol CONST5;
    CommitPol CONST4;
    CommitPol CONST3;
    CommitPol CONST2;
    CommitPol CONST1;
    CommitPol CONST0;
    CommitPol FREE7;
    CommitPol FREE6;
    CommitPol FREE5;
    CommitPol FREE4;
    CommitPol FREE3;
    CommitPol FREE2;
    CommitPol FREE1;
    CommitPol FREE0;
    CommitPol inA;
    CommitPol inB;
    CommitPol inC;
    CommitPol inROTL_C;
    CommitPol inD;
    CommitPol inE;
    CommitPol inSR;
    CommitPol inFREE;
    CommitPol inCTX;
    CommitPol inSP;
    CommitPol inPC;
    CommitPol inGAS;
    CommitPol inMAXMEM;
    CommitPol inSTEP;
    CommitPol inRR;
    CommitPol inHASHPOS;
    CommitPol setA;
    CommitPol setB;
    CommitPol setC;
    CommitPol setD;
    CommitPol setE;
    CommitPol setSR;
    CommitPol setCTX;
    CommitPol setSP;
    CommitPol setPC;
    CommitPol setGAS;
    CommitPol setMAXMEM;
    CommitPol JMP;
    CommitPol JMPN;
    CommitPol JMPC;
    CommitPol setRR;
    CommitPol setHASHPOS;
    CommitPol offset;
    CommitPol incStack;
    CommitPol incCode;
    CommitPol isStack;
    CommitPol isCode;
    CommitPol isMem;
    CommitPol ind;
    CommitPol indRR;
    CommitPol useCTX;
    CommitPol carry;
    CommitPol mOp;
    CommitPol mWR;
    CommitPol sWR;
    CommitPol sRD;
    CommitPol arith;
    CommitPol arithEq0;
    CommitPol arithEq1;
    CommitPol arithEq2;
    CommitPol arithEq3;
    CommitPol memAlign;
    CommitPol memAlignWR;
    CommitPol memAlignWR8;
    CommitPol hashK;
    CommitPol hashKLen;
    CommitPol hashKDigest;
    CommitPol hashP;
    CommitPol hashPLen;
    CommitPol hashPDigest;
    CommitPol bin;
    CommitPol binOpcode;
    CommitPol assert_pol;
    CommitPol isNeg;
    CommitPol isMaxMem;
    CommitPol cntArith;
    CommitPol cntBinary;
    CommitPol cntMemAlign;
    CommitPol cntKeccakF;
    CommitPol cntPoseidonG;
    CommitPol cntPaddingPG;
    CommitPol inCntArith;
    CommitPol inCntBinary;
    CommitPol inCntMemAlign;
    CommitPol inCntKeccakF;
    CommitPol inCntPoseidonG;
    CommitPol inCntPaddingPG;
    CommitPol incCounter;
    CommitPol sKeyI[4];
    CommitPol sKey[4];
private:
    void * _pAddress;
    uint64_t _degree;
public:

    MainCommitPols (void * pAddress, uint64_t degree) :
        A7((Goldilocks::Element *)((uint8_t *)pAddress + 3824), degree, 478),
        A6((Goldilocks::Element *)((uint8_t *)pAddress + 3832), degree, 479),
        A5((Goldilocks::Element *)((uint8_t *)pAddress + 3840), degree, 480),
        A4((Goldilocks::Element *)((uint8_t *)pAddress + 3848), degree, 481),
        A3((Goldilocks::Element *)((uint8_t *)pAddress + 3856), degree, 482),
        A2((Goldilocks::Element *)((uint8_t *)pAddress + 3864), degree, 483),
        A1((Goldilocks::Element *)((uint8_t *)pAddress + 3872), degree, 484),
        A0((Goldilocks::Element *)((uint8_t *)pAddress + 3880), degree, 485),
        B7((Goldilocks::Element *)((uint8_t *)pAddress + 3888), degree, 486),
        B6((Goldilocks::Element *)((uint8_t *)pAddress + 3896), degree, 487),
        B5((Goldilocks::Element *)((uint8_t *)pAddress + 3904), degree, 488),
        B4((Goldilocks::Element *)((uint8_t *)pAddress + 3912), degree, 489),
        B3((Goldilocks::Element *)((uint8_t *)pAddress + 3920), degree, 490),
        B2((Goldilocks::Element *)((uint8_t *)pAddress + 3928), degree, 491),
        B1((Goldilocks::Element *)((uint8_t *)pAddress + 3936), degree, 492),
        B0((Goldilocks::Element *)((uint8_t *)pAddress + 3944), degree, 493),
        C7((Goldilocks::Element *)((uint8_t *)pAddress + 3952), degree, 494),
        C6((Goldilocks::Element *)((uint8_t *)pAddress + 3960), degree, 495),
        C5((Goldilocks::Element *)((uint8_t *)pAddress + 3968), degree, 496),
        C4((Goldilocks::Element *)((uint8_t *)pAddress + 3976), degree, 497),
        C3((Goldilocks::Element *)((uint8_t *)pAddress + 3984), degree, 498),
        C2((Goldilocks::Element *)((uint8_t *)pAddress + 3992), degree, 499),
        C1((Goldilocks::Element *)((uint8_t *)pAddress + 4000), degree, 500),
        C0((Goldilocks::Element *)((uint8_t *)pAddress + 4008), degree, 501),
        D7((Goldilocks::Element *)((uint8_t *)pAddress + 4016), degree, 502),
        D6((Goldilocks::Element *)((uint8_t *)pAddress + 4024), degree, 503),
        D5((Goldilocks::Element *)((uint8_t *)pAddress + 4032), degree, 504),
        D4((Goldilocks::Element *)((uint8_t *)pAddress + 4040), degree, 505),
        D3((Goldilocks::Element *)((uint8_t *)pAddress + 4048), degree, 506),
        D2((Goldilocks::Element *)((uint8_t *)pAddress + 4056), degree, 507),
        D1((Goldilocks::Element *)((uint8_t *)pAddress + 4064), degree, 508),
        D0((Goldilocks::Element *)((uint8_t *)pAddress + 4072), degree, 509),
        E7((Goldilocks::Element *)((uint8_t *)pAddress + 4080), degree, 510),
        E6((Goldilocks::Element *)((uint8_t *)pAddress + 4088), degree, 511),
        E5((Goldilocks::Element *)((uint8_t *)pAddress + 4096), degree, 512),
        E4((Goldilocks::Element *)((uint8_t *)pAddress + 4104), degree, 513),
        E3((Goldilocks::Element *)((uint8_t *)pAddress + 4112), degree, 514),
        E2((Goldilocks::Element *)((uint8_t *)pAddress + 4120), degree, 515),
        E1((Goldilocks::Element *)((uint8_t *)pAddress + 4128), degree, 516),
        E0((Goldilocks::Element *)((uint8_t *)pAddress + 4136), degree, 517),
        SR7((Goldilocks::Element *)((uint8_t *)pAddress + 4144), degree, 518),
        SR6((Goldilocks::Element *)((uint8_t *)pAddress + 4152), degree, 519),
        SR5((Goldilocks::Element *)((uint8_t *)pAddress + 4160), degree, 520),
        SR4((Goldilocks::Element *)((uint8_t *)pAddress + 4168), degree, 521),
        SR3((Goldilocks::Element *)((uint8_t *)pAddress + 4176), degree, 522),
        SR2((Goldilocks::Element *)((uint8_t *)pAddress + 4184), degree, 523),
        SR1((Goldilocks::Element *)((uint8_t *)pAddress + 4192), degree, 524),
        SR0((Goldilocks::Element *)((uint8_t *)pAddress + 4200), degree, 525),
        CTX((Goldilocks::Element *)((uint8_t *)pAddress + 4208), degree, 526),
        SP((Goldilocks::Element *)((uint8_t *)pAddress + 4216), degree, 527),
        PC((Goldilocks::Element *)((uint8_t *)pAddress + 4224), degree, 528),
        GAS((Goldilocks::Element *)((uint8_t *)pAddress + 4232), degree, 529),
        MAXMEM((Goldilocks::Element *)((uint8_t *)pAddress + 4240), degree, 530),
        zkPC((Goldilocks::Element *)((uint8_t *)pAddress + 4248), degree, 531),
        RR((Goldilocks::Element *)((uint8_t *)pAddress + 4256), degree, 532),
        HASHPOS((Goldilocks::Element *)((uint8_t *)pAddress + 4264), degree, 533),
        CONST7((Goldilocks::Element *)((uint8_t *)pAddress + 4272), degree, 534),
        CONST6((Goldilocks::Element *)((uint8_t *)pAddress + 4280), degree, 535),
        CONST5((Goldilocks::Element *)((uint8_t *)pAddress + 4288), degree, 536),
        CONST4((Goldilocks::Element *)((uint8_t *)pAddress + 4296), degree, 537),
        CONST3((Goldilocks::Element *)((uint8_t *)pAddress + 4304), degree, 538),
        CONST2((Goldilocks::Element *)((uint8_t *)pAddress + 4312), degree, 539),
        CONST1((Goldilocks::Element *)((uint8_t *)pAddress + 4320), degree, 540),
        CONST0((Goldilocks::Element *)((uint8_t *)pAddress + 4328), degree, 541),
        FREE7((Goldilocks::Element *)((uint8_t *)pAddress + 4336), degree, 542),
        FREE6((Goldilocks::Element *)((uint8_t *)pAddress + 4344), degree, 543),
        FREE5((Goldilocks::Element *)((uint8_t *)pAddress + 4352), degree, 544),
        FREE4((Goldilocks::Element *)((uint8_t *)pAddress + 4360), degree, 545),
        FREE3((Goldilocks::Element *)((uint8_t *)pAddress + 4368), degree, 546),
        FREE2((Goldilocks::Element *)((uint8_t *)pAddress + 4376), degree, 547),
        FREE1((Goldilocks::Element *)((uint8_t *)pAddress + 4384), degree, 548),
        FREE0((Goldilocks::Element *)((uint8_t *)pAddress + 4392), degree, 549),
        inA((Goldilocks::Element *)((uint8_t *)pAddress + 4400), degree, 550),
        inB((Goldilocks::Element *)((uint8_t *)pAddress + 4408), degree, 551),
        inC((Goldilocks::Element *)((uint8_t *)pAddress + 4416), degree, 552),
        inROTL_C((Goldilocks::Element *)((uint8_t *)pAddress + 4424), degree, 553),
        inD((Goldilocks::Element *)((uint8_t *)pAddress + 4432), degree, 554),
        inE((Goldilocks::Element *)((uint8_t *)pAddress + 4440), degree, 555),
        inSR((Goldilocks::Element *)((uint8_t *)pAddress + 4448), degree, 556),
        inFREE((Goldilocks::Element *)((uint8_t *)pAddress + 4456), degree, 557),
        inCTX((Goldilocks::Element *)((uint8_t *)pAddress + 4464), degree, 558),
        inSP((Goldilocks::Element *)((uint8_t *)pAddress + 4472), degree, 559),
        inPC((Goldilocks::Element *)((uint8_t *)pAddress + 4480), degree, 560),
        inGAS((Goldilocks::Element *)((uint8_t *)pAddress + 4488), degree, 561),
        inMAXMEM((Goldilocks::Element *)((uint8_t *)pAddress + 4496), degree, 562),
        inSTEP((Goldilocks::Element *)((uint8_t *)pAddress + 4504), degree, 563),
        inRR((Goldilocks::Element *)((uint8_t *)pAddress + 4512), degree, 564),
        inHASHPOS((Goldilocks::Element *)((uint8_t *)pAddress + 4520), degree, 565),
        setA((Goldilocks::Element *)((uint8_t *)pAddress + 4528), degree, 566),
        setB((Goldilocks::Element *)((uint8_t *)pAddress + 4536), degree, 567),
        setC((Goldilocks::Element *)((uint8_t *)pAddress + 4544), degree, 568),
        setD((Goldilocks::Element *)((uint8_t *)pAddress + 4552), degree, 569),
        setE((Goldilocks::Element *)((uint8_t *)pAddress + 4560), degree, 570),
        setSR((Goldilocks::Element *)((uint8_t *)pAddress + 4568), degree, 571),
        setCTX((Goldilocks::Element *)((uint8_t *)pAddress + 4576), degree, 572),
        setSP((Goldilocks::Element *)((uint8_t *)pAddress + 4584), degree, 573),
        setPC((Goldilocks::Element *)((uint8_t *)pAddress + 4592), degree, 574),
        setGAS((Goldilocks::Element *)((uint8_t *)pAddress + 4600), degree, 575),
        setMAXMEM((Goldilocks::Element *)((uint8_t *)pAddress + 4608), degree, 576),
        JMP((Goldilocks::Element *)((uint8_t *)pAddress + 4616), degree, 577),
        JMPN((Goldilocks::Element *)((uint8_t *)pAddress + 4624), degree, 578),
        JMPC((Goldilocks::Element *)((uint8_t *)pAddress + 4632), degree, 579),
        setRR((Goldilocks::Element *)((uint8_t *)pAddress + 4640), degree, 580),
        setHASHPOS((Goldilocks::Element *)((uint8_t *)pAddress + 4648), degree, 581),
        offset((Goldilocks::Element *)((uint8_t *)pAddress + 4656), degree, 582),
        incStack((Goldilocks::Element *)((uint8_t *)pAddress + 4664), degree, 583),
        incCode((Goldilocks::Element *)((uint8_t *)pAddress + 4672), degree, 584),
        isStack((Goldilocks::Element *)((uint8_t *)pAddress + 4680), degree, 585),
        isCode((Goldilocks::Element *)((uint8_t *)pAddress + 4688), degree, 586),
        isMem((Goldilocks::Element *)((uint8_t *)pAddress + 4696), degree, 587),
        ind((Goldilocks::Element *)((uint8_t *)pAddress + 4704), degree, 588),
        indRR((Goldilocks::Element *)((uint8_t *)pAddress + 4712), degree, 589),
        useCTX((Goldilocks::Element *)((uint8_t *)pAddress + 4720), degree, 590),
        carry((Goldilocks::Element *)((uint8_t *)pAddress + 4728), degree, 591),
        mOp((Goldilocks::Element *)((uint8_t *)pAddress + 4736), degree, 592),
        mWR((Goldilocks::Element *)((uint8_t *)pAddress + 4744), degree, 593),
        sWR((Goldilocks::Element *)((uint8_t *)pAddress + 4752), degree, 594),
        sRD((Goldilocks::Element *)((uint8_t *)pAddress + 4760), degree, 595),
        arith((Goldilocks::Element *)((uint8_t *)pAddress + 4768), degree, 596),
        arithEq0((Goldilocks::Element *)((uint8_t *)pAddress + 4776), degree, 597),
        arithEq1((Goldilocks::Element *)((uint8_t *)pAddress + 4784), degree, 598),
        arithEq2((Goldilocks::Element *)((uint8_t *)pAddress + 4792), degree, 599),
        arithEq3((Goldilocks::Element *)((uint8_t *)pAddress + 4800), degree, 600),
        memAlign((Goldilocks::Element *)((uint8_t *)pAddress + 4808), degree, 601),
        memAlignWR((Goldilocks::Element *)((uint8_t *)pAddress + 4816), degree, 602),
        memAlignWR8((Goldilocks::Element *)((uint8_t *)pAddress + 4824), degree, 603),
        hashK((Goldilocks::Element *)((uint8_t *)pAddress + 4832), degree, 604),
        hashKLen((Goldilocks::Element *)((uint8_t *)pAddress + 4840), degree, 605),
        hashKDigest((Goldilocks::Element *)((uint8_t *)pAddress + 4848), degree, 606),
        hashP((Goldilocks::Element *)((uint8_t *)pAddress + 4856), degree, 607),
        hashPLen((Goldilocks::Element *)((uint8_t *)pAddress + 4864), degree, 608),
        hashPDigest((Goldilocks::Element *)((uint8_t *)pAddress + 4872), degree, 609),
        bin((Goldilocks::Element *)((uint8_t *)pAddress + 4880), degree, 610),
        binOpcode((Goldilocks::Element *)((uint8_t *)pAddress + 4888), degree, 611),
        assert_pol((Goldilocks::Element *)((uint8_t *)pAddress + 4896), degree, 612),
        isNeg((Goldilocks::Element *)((uint8_t *)pAddress + 4904), degree, 613),
        isMaxMem((Goldilocks::Element *)((uint8_t *)pAddress + 4912), degree, 614),
        cntArith((Goldilocks::Element *)((uint8_t *)pAddress + 4920), degree, 615),
        cntBinary((Goldilocks::Element *)((uint8_t *)pAddress + 4928), degree, 616),
        cntMemAlign((Goldilocks::Element *)((uint8_t *)pAddress + 4936), degree, 617),
        cntKeccakF((Goldilocks::Element *)((uint8_t *)pAddress + 4944), degree, 618),
        cntPoseidonG((Goldilocks::Element *)((uint8_t *)pAddress + 4952), degree, 619),
        cntPaddingPG((Goldilocks::Element *)((uint8_t *)pAddress + 4960), degree, 620),
        inCntArith((Goldilocks::Element *)((uint8_t *)pAddress + 4968), degree, 621),
        inCntBinary((Goldilocks::Element *)((uint8_t *)pAddress + 4976), degree, 622),
        inCntMemAlign((Goldilocks::Element *)((uint8_t *)pAddress + 4984), degree, 623),
        inCntKeccakF((Goldilocks::Element *)((uint8_t *)pAddress + 4992), degree, 624),
        inCntPoseidonG((Goldilocks::Element *)((uint8_t *)pAddress + 5000), degree, 625),
        inCntPaddingPG((Goldilocks::Element *)((uint8_t *)pAddress + 5008), degree, 626),
        incCounter((Goldilocks::Element *)((uint8_t *)pAddress + 5016), degree, 627),
        sKeyI{
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 5024), degree, 628),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 5032), degree, 629),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 5040), degree, 630),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 5048), degree, 631)
        },
        sKey{
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 5056), degree, 632),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 5064), degree, 633),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 5072), degree, 634),
            CommitPol((Goldilocks::Element *)((uint8_t *)pAddress + 5080), degree, 635)
        },
        _pAddress(pAddress),
        _degree(degree) {};

    static uint64_t pilDegree (void) { return 2097152; }
    static uint64_t pilSize (void) { return 1264; }
    static uint64_t numPols (void) { return 158; }

    void * address (void) { return _pAddress; }
    uint64_t degree (void) { return _degree; }
    uint64_t size (void) { return _degree*158*sizeof(Goldilocks::Element); }
};

class CommitPols
{
public:
    Byte4CommitPols Byte4;
    MemAlignCommitPols MemAlign;
    ArithCommitPols Arith;
    BinaryCommitPols Binary;
    PoseidonGCommitPols PoseidonG;
    PaddingPGCommitPols PaddingPG;
    StorageCommitPols Storage;
    NormGate9CommitPols NormGate9;
    KeccakFCommitPols KeccakF;
    Nine2OneCommitPols Nine2One;
    PaddingKKBitCommitPols PaddingKKBit;
    PaddingKKCommitPols PaddingKK;
    MemCommitPols Mem;
    MainCommitPols Main;
private:
    void * _pAddress;
    uint64_t _degree;
public:

    CommitPols (void * pAddress, uint64_t degree) :
        Byte4(pAddress, degree),
        MemAlign(pAddress, degree),
        Arith(pAddress, degree),
        Binary(pAddress, degree),
        PoseidonG(pAddress, degree),
        PaddingPG(pAddress, degree),
        Storage(pAddress, degree),
        NormGate9(pAddress, degree),
        KeccakF(pAddress, degree),
        Nine2One(pAddress, degree),
        PaddingKKBit(pAddress, degree),
        PaddingKK(pAddress, degree),
        Mem(pAddress, degree),
        Main(pAddress, degree),
        _pAddress(pAddress),
        _degree(degree) {}

    static uint64_t pilSize (void) { return 10670309376; }
    static uint64_t pilDegree (void) { return 2097152; }
    static uint64_t numPols (void) { return 636; }

    void * address (void) { return _pAddress; }
    uint64_t degree (void) { return _degree; }
    uint64_t size (void) { return _degree*636*sizeof(Goldilocks::Element); }

    Goldilocks::Element &getElement (uint64_t pol, uint64_t evaluation)
    {
        zkassert((pol < numPols()) && (evaluation < degree()));
        return ((Goldilocks::Element *)_pAddress)[pol + evaluation * numPols()];
    }
};

#endif // COMMIT_POLS_HPP
