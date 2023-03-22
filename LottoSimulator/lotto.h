
#ifndef ___LOTTO_H___ASDFASKDFAHDMFDHDD____
#define ___LOTTO_H___ASDFASKDFAHDMFDHDD____

#include <stdio.h>
#include <stdlib.h> // rand()를 사용하기 위해서
#include <time.h>

#define LOTTO_MAX       45
#define LOTTO_NUMS      6
#define LOTTO_ROWS      5

typedef unsigned char   byte;

void initLotto(byte* arr, int nSize);

void swap(byte* a, byte* b);

void sortArr(byte* arr, int nSize);

byte findInArray(byte* arr, int nSize, byte toFind);


#endif