/**
 *  백준 2588: 곱셈

문제
    (세 자리 수) × (세 자리 수)는 다음과 같은 과정을 통하여 이루어진다.
    (1)과 (2)위치에 들어갈 세 자리 자연수가 주어질 때 (3), (4), (5), (6)위치에 들어갈 값을 구하는 프로그램을 작성하시오.

입력
    첫째 줄에 (1)의 위치에 들어갈 세 자리 자연수가, 둘째 줄에 (2)의 위치에 들어갈 세자리 자연수가 주어진다.

출력
    첫째 줄부터 넷째 줄까지 차례대로 (3), (4), (5), (6)에 들어갈 값을 출력한다.

 *  https://www.acmicpc.net/problem/2588
**/

#if 1

#include <iostream>

int main()
{
    int A, B;
    std::cin >> A >> B;
    std::cout << A * (B % 10) << "\n";
    std::cout << A * ((B % 100) / 10) << "\n";
    std::cout << A * (B / 100) << "\n";
    std::cout << A * B << "\n";
}

#endif

#if 0

#include <iostream>
using namespace std;
 
int main(int argc, char const *argv[]) {
    int A;
    char B[4];
 
    cin >> A;
    cin >> B;
 
    cout << A * (B[2] - '0') << "\n";
    cout << A * (B[1] - '0') << "\n";
    cout << A * (B[0] - '0') << "\n";
    cout << A * atoi(B) << "\n";
    return 0;
}

#endif

#if 0

#include <iostream>
#include <string> // string, stoi()을 쓰기 위한 헤더파일
 
using namespace std;
 
int main(int argc, char const *argv[]) {
    int A;
    string B;
 
    cin >> A;
    cin >> B;
 
    cout << A * (B[2] - '0') << "\n";
    cout << A * (B[1] - '0') << "\n";
    cout << A * (B[0] - '0') << "\n";
    cout << A * stoi(B) << "\n";    // string -> int(10진수) 로 변환
    return 0;
}

#endif