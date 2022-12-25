/**
 *  백준 2577: 숫자의 개수

문제
    세 개의 자연수 A, B, C가 주어질 때 A × B × C를 계산한 결과에 0부터 9까지 각각의 숫자가 몇 번씩 쓰였는지를 구하는 프로그램을 작성하시오.
    예를 들어 A = 150, B = 266, C = 427 이라면 A × B × C = 150 × 266 × 427 = 17037300 이 되고, 계산한 결과 17037300 에는 0이 3번, 1이 1번, 3이 2번, 7이 2번 쓰였다.

입력
    첫째 줄에 A, 둘째 줄에 B, 셋째 줄에 C가 주어진다. A, B, C는 모두 100보다 크거나 같고, 1,000보다 작은 자연수이다.

출력
    첫째 줄에는 A × B × C의 결과에 0 이 몇 번 쓰였는지 출력한다. 마찬가지로 둘째 줄부터 열 번째 줄까지 A × B × C의 결과에 1부터 9까지의 숫자가 각각 몇 번 쓰였는지 차례로 한 줄에 하나씩 출력한다.

 *  https://www.acmicpc.net/problem/2577
**/

#include <iostream>

int main()
{
    int A, B, C;
    int number[10] = {};
    std::cin >> A >> B >> C;
    std::string result = std::to_string(A * B * C);
    for (int i = 0; i < result.length(); i++)
    {
        switch (result.at(i))
        {
        case '0':
            number[0]++;
            break;
        case '1':
            number[1]++;
            break;
        case '2':
            number[2]++;
            break;
        case '3':
            number[3]++;
            break;
        case '4':
            number[4]++;
            break;
        case '5':
            number[5]++;
            break;
        case '6':
            number[6]++;
            break;
        case '7':
            number[7]++;
            break;
        case '8':
            number[8]++;
            break;
        case '9':
            number[9]++;
            break;
        }
    }
    for (int i = 0; i < 10; i++)
        std::cout << number[i] << "\n";
}

/* BETTER WAY
    for (char ch : result) {		// 문자열의 문자들을 하나씩 꺼내온다. (foreach문 활용)
        // 문자를 숫자로 변환한 값의 인덱스를 1 증가시킨다.
        number[ch - '0']++;
    }

    // 0 부터 9까지 count 배열을 출력한다. (foreach문 사용)
    for (int v : number) {
        std::cout << v << "\n";
    }
    return 0;
}
*/
