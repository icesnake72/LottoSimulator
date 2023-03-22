
#include "lotto.h"



// arr(배열)안에 toFind가 있는지 검색하는 함수
// toFind가 arr(배열)안에 같은 값이 있으면 1을 반환
// 같은 값이 없으면 0을 반환!!!
byte findInArray(byte* arr, int nSize, byte toFind)
{
    for (int i = 0; i < nSize; i++)
    {
        if (arr[i] == toFind)
            return 1;
    }

    return 0;
}

// 1차원 배열만 처리가 가능하도록 만들어짐
void initLotto(byte* arr, int nSize)
{
    byte i = 0;
    while (i < LOTTO_NUMS)
    {
        int rnd = (rand() % LOTTO_MAX) + 1;
        if (findInArray(arr, nSize, rnd))
            continue;

        arr[i++] = rnd;
    }
}


// Call by Reference(참조)
void swap(byte* a, byte* b)
{
    byte tmp = *a;
    *a = *b;
    *b = tmp;
}


void sortArr(byte* arr, int nSize)
{
    for (byte i = 0; i < LOTTO_NUMS - 1; i++)
    {
        for (byte j = i + 1; j < LOTTO_NUMS; j++)
        {
            if (arr[i] > arr[j])
            {
                swap(&arr[i], &arr[j]);
            }
        }
    }
}

