/**
 *  백준 1427: 소트인사이드

문제
    전자 제품에는 저항이 들어간다. 저항은 색 3개를 이용해서 그 저항이 몇 옴인지 나타낸다. 처음 색 2개는 저항의 값이고, 마지막 색은 곱해야 하는 값이다. 저항의 값은 다음 표를 이용해서 구한다.

    색	    값	곱
    black	0	1
    brown	1	10
    red	    2	100
    orange	3	1,000
    yellow	4	10,000
    green	5	100,000
    blue	6	1,000,000
    violet	7	10,000,000
    grey	8	100,000,000
    white	9	1,000,000,000

    예를 들어, 저항의 색이 yellow, violet, red였다면 저항의 값은 4,700이 된다.

입력
    첫째 줄에 첫 번째 색, 둘째 줄에 두 번째 색, 셋째 줄에 세 번째 색이 주어진다.
    위의 표에 있는 색만 입력으로 주어진다.

출력
    입력으로 주어진 저항의 저항값을 계산하여 첫째 줄에 출력한다.

 *  https://www.acmicpc.net/problem/1427
**/

#include <iostream>
#include <iomanip>

struct resistance
{
    std::string colour;
    int value;
    double multiple;
};

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    resistance array[10];
    array[0] = {"black", 0, 1};
    array[1] = {"brown", 1, 10};
    array[2] = {"red", 2, 100};
    array[3] = {"orange", 3, 1000};
    array[4] = {"yellow", 4, 10000};
    array[5] = {"green", 5, 100000};
    array[6] = {"blue", 6, 1000000};
    array[7] = {"violet", 7, 10000000};
    array[8] = {"grey", 8, 100000000};
    array[9] = {"white", 9, 1000000000};

    std::string c1, c2, c3;
    double sum = 0, multiple = 1;

    std::cin >> c1 >> c2 >> c3;
    for (int i = 0; i < 10; i++)
    {
        if (c1 == array[i].colour)
            sum += array[i].value * 10;
        if (c2 == array[i].colour)
            sum += array[i].value;
        if (c3 == array[i].colour)
            multiple = array[i].multiple;
    }
    sum *= multiple;
    std::cout << std::fixed << std::setprecision(0) << sum;
}