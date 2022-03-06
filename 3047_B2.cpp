/**
 *  백준 3047: ABC

문제
    세 수 A, B, C가 주어진다. A는 B보다 작고, B는 C보다 작다.

    세 수 A, B, C가 주어졌을 때, 입력에서 주어진 순서대로 출력하는 프로그램을 작성하시오.

입력
    첫째 줄에 세 수 A, B, C가 주어진다.
    하지만, 순서는 A, B, C가 아닐 수도 있다.

    세 수는 100보다 작거나 같은 자연수이다.
    둘째 줄에는 A, B, C로 이루어진 세 글자가 주어지며, 이 순서대로 출력하면 된다.

출력
    주어진 세 수를 주어진 출력 순서대로 출력하면 된다.

 *  https://www.acmicpc.net/problem/3047
**/

#include <iostream>
#include <algorithm>

int main()
{
    int A, B, C, num[3];
    char char1, char2, char3;
    std::cin >> num[0] >> num[1] >> num[2];
    std::sort(num, num + 3);
    A = num[0];
    B = num[1];
    C = num[2];

    std::cin >> char1 >> char2 >> char3;
    if (char1 == 'A')
        std::cout << A << " ";
    else if (char1 == 'B')
        std::cout << B << " ";
    else if (char1 == 'C')
        std::cout << C << " ";
    if (char2 == 'A')
        std::cout << A << " ";
    else if (char2 == 'B')
        std::cout << B << " ";
    else if (char2 == 'C')
        std::cout << C << " ";
    if (char3 == 'A')
        std::cout << A << " ";
    else if (char3 == 'B')
        std::cout << B << " ";
    else if (char3 == 'C')
        std::cout << C << " ";
}