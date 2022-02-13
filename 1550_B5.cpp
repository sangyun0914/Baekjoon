/**
 *  백준 1550: 16진수

문제
    16진수 수를 입력받아서 10진수로 출력하는 프로그램을 작성하시오.

입력
    첫째 줄에 16진수 수가 주어진다.
    이 수의 최대 길이는 6글자이다.
    16진수 수는 0~9와 A~F로 이루어져 있고, A~F는 10~15를 뜻한다.
    또, 이 수는 음이 아닌 정수이다.

출력
    첫째 줄에 입력으로 주어진 16진수 수를 10진수로 변환해 출력한다.

 *  https://www.acmicpc.net/problem/1550
**/

#if 0

#include <iostream>
#include <string>
#include <cmath>

int main()
{
    int dec = 0, sum = 0;
    std::string hex;
    std::cin >> hex;
    for (unsigned int i = 0; i < hex.length(); i++)
    {
        if (isdigit(hex[i]))
            dec = int(hex[i]) - '0';
        else
            switch (hex[i])
            {
            case 'A':
                dec = 10;
                break;
            case 'B':
                dec = 11;
                break;
            case 'C':
                dec = 12;
                break;
            case 'D':
                dec = 13;
                break;
            case 'E':
                dec = 14;
                break;
            case 'F':
                dec = 15;
                break;
            }
        sum += dec * pow(16, hex.length() - 1 - i);
    }
    std::cout << sum;
}

#endif

#if 1 // MUCH BETTER

#include <iostream>

int main()
{
    int input;
    scanf("%X", &input); // 대문자 16진수 표기 입력
    printf("%d", input); // 10진수 출력 입력
    return 0;
}

#endif

#if 0 // Little better

#include <iostream>
#include <string>
using namespace std;
 
int main(int argc, char* argv[])
{
	int num = 0;
	string s;
 
	cin >> s;
 
	for (int i = 0; i < s.length(); ++i) {
		num *= 16;
 
		if (s[i] >= 'A' && s[i] <= 'F') {
			num += s[i] - 'A' + 10;
		}
		else {
			num += s[i] - '0';
		}		
	}
	cout << num << endl;
 
	return 0;

#endif