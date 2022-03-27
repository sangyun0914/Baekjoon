/**
 *  백준 1373: 2진수 8진수

문제
    2진수가 주어졌을 때, 8진수로 변환하는 프로그램을 작성하시오.

입력
    첫째 줄에 2진수가 주어진다. 주어지는 수의 길이는 1,000,000을 넘지 않는다.

출력
    첫째 줄에 주어진 수를 8진수로 변환하여 출력한다.

 *  https://www.acmicpc.net/problem/2373
**/

#include <iostream>
#include <cstring>
#include <string>

int main()
{
    std::string binary;
    std::cin >> binary;

    char cBinary[binary.length() + 1];
    strcpy(cBinary, binary.c_str());

    std::cout << std::__cxx11::stoi(cBinary, 0, 2);
}