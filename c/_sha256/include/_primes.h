


#ifndef __PRIMES_H
  #define __PRIMES_H    0x1
  #include <stdio.h>
  #include <stdlib.h>

  __uint32_t list_primes[64] = {
    0x2,   0x3,   0x5,   0x7,   0xb,   0xd,   0x11,  0x13,
    0x17,  0x1d,  0x1f,  0x25,  0x29,  0x2b,  0x2f,  0x35,
    0x3b,  0x3d,  0x43,  0x47,  0x49,  0x4f,  0x53,  0x59,
    0x61,  0x65,  0x67,  0x6b,  0x6d,  0x71,  0x7f,  0x83,
    0x89,  0x8b,  0x95,  0x97,  0x9d,  0xa3,  0xa7,  0xad,
    0xb3,  0xb5,  0xbf,  0xc1,  0xc5,  0xc7,  0xd3,  0xdf,
    0xe3,  0xe5,  0xe9,  0xef,  0xf1,  0xfb,  0x101, 0x107,
    0x10d, 0x10f, 0x115, 0x119, 0x11b, 0x125, 0x133, 0x137
  };
  
  double list_sqr_roots[64] = {     
    1.41421356237,  1.73205080756,  2.23606797749,  2.64575131106,  3.31662479035,  3.60555127546,  4.12310562561,  4.35889894353,
    4.79583152331,  5.38516480713,  5.56776436283,  6.08276253030,  6.40312423743,  6.55743852430,  6.85565460040,  7.28010988928,
    7.68114574787,  7.81024967591,  8.18535277187,  8.42614977317,  8.54400374532,  8.88819441731,  9.11043357914,  9.43398113205,
    9.84885780179,  10.04987562112, 10.14889156509, 10.34408043278, 10.44030650891, 10.63014581273, 11.26942766958, 11.44552314226,
    11.70469991072, 11.78982612255, 12.20655561573, 12.28820572744, 12.52996408614, 12.76714533480, 12.92284798332, 13.15294643796,
    13.37908816026, 13.45362404707, 13.82027496108, 13.89244398945, 14.03566884762, 14.10673597966, 14.52583904633, 14.93318452306,
    15.06651917332, 15.13274595042, 15.26433752247, 15.45962483374, 15.52417469626, 15.84297951775, 16.03121954188, 16.21727474023,
    16.40121946686, 16.46207763315, 16.64331697709, 16.76305461423, 16.82260384126, 17.11724276862, 17.52141546793, 17.63519208855
  };

  double list_cube_roots[64] = {
    1.25992012024 ,1.44224953651 ,1.70997560024, 1.91293096542, 2.22397965193, 2.35133397579, 2.57128149271, 2.66840109229, 
    2.84386670589, 3.07231658697, 3.14138004184, 3.33222149312, 3.44821701944, 3.50339764357, 3.60882557929, 3.75628517568,
    3.89299596846, 3.93649634719, 4.06154765189, 4.14081738889, 4.17933869362, 4.29084032774, 4.36207013577, 4.46474446356, 
    4.59470081329, 4.65700883418, 4.68754780293, 4.74745878577, 4.77685602754, 4.83458755910, 5.02652499825, 5.07875256985,
    5.15513636917, 5.18010101840, 5.30145911872, 5.32507386431, 5.39469062537, 5.46255497634, 5.50687840208, 5.57205414027,
    5.63574076071, 5.65665254369, 5.75896520913, 5.77899622545, 5.81864731386, 5.83827207610, 5.95334111154, 6.06412676349,
    6.10017014667, 6.11803255230, 6.15344893560, 6.20582142472, 6.22308373451, 6.30799278989, 6.35786101222, 6.40695853531,
    6.45531461760, 6.47127335519, 6.51868373528, 6.54991112836, 6.56541436724, 6.64185179770, 6.74599660188, 6.77516870387
  };
#endif