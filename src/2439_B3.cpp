/**
 *  백준 2439: 별 찍기 - 2

문제
    첫째 줄에는 별 1개, 둘째 줄에는 별 2개, N번째 줄에는 별 N개를 찍는 문제
    하지만, 오른쪽을 기준으로 정렬한 별(예제 참고)을 출력하시오.

5:
    *
   **
  ***
 ****
*****

입력
    첫째 줄에 N(1 ≤ N ≤ 100)이 주어진다.

출력
    첫째 줄부터 N번째 줄까지 차례대로 별을 출력한다.

 *  https://www.acmicpc.net/problem/2439
**/

#include <iostream>

int main()
{
    int num;
    std::cin >> num;
    for (int i = 1; i <= num; i++)
    {
        for (int j = 1; j <= num - i; j++)
            std::cout << " ";
        for (int j = num - i + 1; j <= num; j++)
            std::cout << "*";
        std::cout << std::endl;
    }
}