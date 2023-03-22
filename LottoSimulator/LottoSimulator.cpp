// 로또 시뮬레이터

// 미션 :
// 로또 당첨번호 6개를 랜덤으로 생성한다.
// 로또 당첨번호 6개를 오름차순 정렬하여 출력한다.
//
// 구매자 시뮬레이션을 위해 5행 6열 2차원 배열에 랜덤 로또 번호를 생성하여 저장한다.
// 구매자 로또번호와 당첨번호를 맞춰보고
// 6개가 모두 맞으면 1등
// 5개가 맞으면 2등
// 4개가 맞으면 3등
// 3개가 맞으면 4등 을 해당 라인 옆에 출력한다.
// 3개 미만으로 맞으면 꽝 과 맞은 갯수를 출력한다


/*
로또 당첨 번호
=========================
10, 11, 15, 16, 29, 32,
=========================
구매자 로또 번호
=========================
10, 11, 15, 16, 29, 32, <=== 1등
10, 11, 15, 20, 27, 30, <=== 4등
 1,  3, 14, 20, 27, 30, <=== 꽝(0)
 7, 23, 30, 32, 38, 45, <=== 꽝(1)
15, 19, 31, 32, 42, 44, <=== 꽝(1)
*/

#include "lotto.h"

int main()
{
    // 랜덤 초기화!!!
    srand((unsigned int)time(NULL));

    byte arrWins[LOTTO_NUMS] = {0};
    initLotto(arrWins, LOTTO_NUMS);
        
    // 오름차순 정렬, 작은숫자에서 큰숫자로===>>>
    sortArr(arrWins, LOTTO_NUMS);

    printf("\n");
    for (byte i = 0; i < LOTTO_NUMS; i++)
    {
        printf("%2d, ", arrWins[i]);
    }

    // 구매자가 갖게되는 자동 랜덤 번호!!!
    byte arrCust[LOTTO_ROWS][LOTTO_NUMS] = {0};
        
    for (byte i = 0; i < LOTTO_ROWS; i++)
        initLotto(arrCust[i], LOTTO_NUMS);

    for (byte i = 0; i < LOTTO_ROWS; i++)
        sortArr(arrCust[i], LOTTO_NUMS);

    printf("\n");

    char* strInfo = NULL;
    byte count = 0;
    for (byte i = 0; i < LOTTO_ROWS; i++)// 5행
    {
        for (byte j = 0; j < LOTTO_NUMS; j++)// 6열
        {
            if (findInArray(arrWins, LOTTO_NUMS, arrCust[i][j]))
                count++;

            printf("%2d, ", arrCust[i][j]);
        }

        printf("===> ");

        switch (count)
        {
        case 6: 
            strInfo = (char *)"1등";             
            break;

        case 5:
            strInfo = (char*)"2등";            
            break;

        case 4:
            strInfo = (char*)"3등";            
            break;

        case 3:
            strInfo = (char*)"4등";            
            break;

        case 2:
        case 1:
        case 0:
            strInfo = (char*)"꽝";
        }

        printf("%s", strInfo);
        if (count < 3)
            printf("(%d)", count);

        count = 0;

        printf("\n");
    }
    
    return 0;
}


