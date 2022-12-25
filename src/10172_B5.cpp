/**
 *  백준 10172: 개

문제
    아래 예제와 같이 개를 출력하시오.

|\_/|
|q p|   /}
( 0 )"""\
|"^"`    |
||_/=\\__|

입력
    없음.

출력
    개를 출력한다.

 *  https://www.acmicpc.net/problem/10172
**/

#include <iostream>

int main()
{
    std::cout << R"(|\_/|)" << std::endl;
    std::cout << R"(|q p|   /})" << std::endl;
    std::cout << "( 0 )\"\"\"\\" << std::endl;
    std::cout << R"(|"^"`    |)" << std::endl;
    std::cout << R"(||_/=\\__|)" << std::endl;
}