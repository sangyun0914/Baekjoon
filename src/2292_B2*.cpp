/**
 *  백준 2292: 벌집

문제
    위의 그림과 같이 육각형으로 이루어진 벌집이 있다.
    그림에서 보는 바와 같이 중앙의 방 1부터 시작해서 이웃하는 방에 돌아가면서 1씩 증가하는 번호를 주소로 매길 수 있다.
    숫자 N이 주어졌을 때, 벌집의 중앙 1에서 N번 방까지 최소 개수의 방을 지나서 갈 때 몇 개의 방을 지나가는지(시작과 끝을 포함하여)를 계산하는 프로그램을 작성하시오.
    예를 들면, 13까지는 3개, 58까지는 5개를 지난다.

입력
    첫째 줄에 N(1 ≤ N ≤ 1,000,000,000)이 주어진다.

출력
    입력으로 주어진 방까지 최소 개수의 방을 지나서 갈 때 몇 개의 방을 지나는지 출력한다.

 *  https://www.acmicpc.net/problem/2292
**/

#if 1
#include <iostream>

int main()
{
    int N, i = 8, count = 1;
    std::cin >> N;
    if (N == 1)
    {
        std::cout << count;
        exit(0);
    }

    while (true)
    {
        count++;
        if ((N / i) < 1)
            break;
        else
            i += 6 * count;
    }
    std::cout << count;
}

#endif

#if 0 // Better code

#include <iostream>
using namespace std;
int main()
{
    int number;
    cin >> number;
    int i = 0;
    for (int sum = 2; sum <= number; i++)
        sum += 6 * i;
    if (number == 1)
        i = 1;
    cout << i;
    return 0;
}

#endif
