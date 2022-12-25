/**
 *  백준 11050: 이항 계수 1

문제
    자연수 N과 정수 K가 주어졌을 때 이항 계수 (N K)를 구하는 프로그램을 작성하시오.

입력
    첫째 줄에 N과 K가 주어진다. (1 ≤ N ≤ 10, 0 ≤ K ≤ N)

출력

    (N K)를 출력한다.

 *  https://www.acmicpc.net/problem/11050
**/

#if 1

#include <iostream>
int main()
{
    int N, K, facN = 1, facK = 1, facNK = 1;
    std::cin >> N >> K;
    for (int i = N; i >= 1; i--)
        facN = facN * i;
    for (int i = K; i >= 1; i--)
        facK = facK * i;
    for (int i = N - K; i >= 1; i--)
        facNK = facNK * i;
    std::cout << facN / (facK * facNK);
}

#endif

#if 0
#include <iostream>

int factorial(int num)
{
    if (num == 1 || num == 0) // why time over when if (num == 1)?
        return 1;
    return num * factorial(num - 1);
}
int main()
{
    int N, K;
    std::cin >> N >> K;
    // std::cout << factorial(N);
    std::cout << factorial(N) / (factorial(K) * factorial(N - K));
}

#endif
