/**
 *  백준 10818: 최소, 최대

문제
    N개의 정수가 주어진다. 이때, 최솟값과 최댓값을 구하는 프로그램을 작성하시오.

입력
    첫째 줄에 정수의 개수 N (1 ≤ N ≤ 1,000,000)이 주어진다. 둘째 줄에는 N개의 정수를 공백으로 구분해서 주어진다. 모든 정수는 -1,000,000보다 크거나 같고, 1,000,000보다 작거나 같은 정수이다.

출력
    첫째 줄에 주어진 정수 N개의 최솟값과 최댓값을 공백으로 구분해 출력한다.

 *  https://www.acmicpc.net/problem/10818
**/

#include <iostream>

int main()
{
    int nums, min, max;
    std::cin >> nums;
    int array[nums];

    for (int i = 0; i < nums; i++)
        std::cin >> array[i];

    min = array[0];
    max = array[0];

    for (int i = 1; i < nums; i++)
    {
        if (min > array[i])
            min = array[i];
        if (max < array[i])
            max = array[i];
    }

    std::cout << min << " " << max;
}