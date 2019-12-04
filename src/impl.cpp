#include "impl.h"
#include <cstdio>

/*
 * binaryInvert.cpp
 *
 *  Created on: 15 ����. 2017 �.
 *      Author: Pavel Tsytovich
 */

int BinaryInvert(int x,int p,int n)
{
    return x ^ ((((0xFFFFFFFF >> (p+1-n)) << (p+1-n)) << ((sizeof(int)*8)-p-1)) >> ((sizeof(int)*8)-p-1));
}
