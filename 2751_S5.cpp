/**
 *  백준 2751: 수 정렬하기 2

문제
    N개의 수가 주어졌을 때, 이를 오름차순으로 정렬하는 프로그램을 작성하시오.

입력
    첫째 줄에 수의 개수 N(1 ≤ N ≤ 1,000,000)이 주어진다.
    둘째 줄부터 N개의 줄에는 수가 주어진다.
    이 수는 절댓값이 1,000,000보다 작거나 같은 정수이다. 수는 중복되지 않는다.

출력
    첫째 줄부터 N개의 줄에 오름차순으로 정렬한 결과를 한 줄에 하나씩 출력한다.

FAQ: SORTING
    https://www.acmicpc.net/board/view/31887

 *  https://www.acmicpc.net/problem/2751
**/

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int N, num;
    std::cin >> N;
    std::vector<int> v;
    for (int i = 0; i < N; i++)
    {
        std::cin >> num;
        v.push_back(num);
    }
    std::sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
        if (v[i] == v[i + 1])
            continue;
        else
            std::cout << v[i] << "\n";
}

#if 0 // Timeout

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int N, num;
    std::cin >> N;
    std::vector<int> v;
    for (int i = 0; i < N; i++)
    {
        std::cin >> num;
        if (find(v.begin(), v.end(), num) == v.end())
            v.push_back(num);
    }
    std::sort(v.begin(), v.end());
    for (auto x : v)
        std::cout << x << "\n";
}

#endif