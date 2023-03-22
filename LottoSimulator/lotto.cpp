
#include "lotto.h"



// arr(�迭)�ȿ� toFind�� �ִ��� �˻��ϴ� �Լ�
// toFind�� arr(�迭)�ȿ� ���� ���� ������ 1�� ��ȯ
// ���� ���� ������ 0�� ��ȯ!!!
byte findInArray(byte* arr, int nSize, byte toFind)
{
    for (int i = 0; i < nSize; i++)
    {
        if (arr[i] == toFind)
            return 1;
    }

    return 0;
}

// 1���� �迭�� ó���� �����ϵ��� �������
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


// Call by Reference(����)
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

