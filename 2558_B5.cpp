/**
 *  백준 2558: A+B - 2

문제
    두 정수 A와 B를 입력받은 다음, A+B를 출력하는 프로그램을 작성하시오.

입력
    첫째 줄에 A, 둘째 줄에 B가 주어진다. (0 < A, B < 10)

출력
    첫째 줄에 A+B를 출력한다.

 *  https://www.acmicpc.net/problem/2558
**/

#include <iostream>

int main()
{
    int A, B;
    std::cin >> A >> B;
    std::cout << A + B;
}