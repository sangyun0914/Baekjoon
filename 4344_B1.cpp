/**
 *  백준 4344: 평균은 넘겠지

문제
    대학생 새내기들의 90%는 자신이 반에서 평균은 넘는다고 생각한다. 당신은 그들에게 슬픈 진실을 알려줘야 한다.

입력
    첫째 줄에는 테스트 케이스의 개수 C가 주어진다.

    둘째 줄부터 각 테스트 케이스마다 학생의 수 N(1 ≤ N ≤ 1000, N은 정수)이 첫 수로 주어지고,
    이어서 N명의 점수가 주어진다. 점수는 0보다 크거나 같고, 100보다 작거나 같은 정수이다.

출력
    각 케이스마다 한 줄씩 평균을 넘는 학생들의 비율을 반올림하여 소수점 셋째 자리까지 출력한다.

 *  https://www.acmicpc.net/problem/4344
**/

#if 1

#include <iostream>

int main()
{
    int num;
    std::cin >> num;
    std::cout << std::fixed;
    std::cout.precision(3);
    for (int i = 0; i < num; i++)
    {
        int students, sum = 0, count = 0;
        float avg = 0;
        std::cin >> students;
        int scores[students];
        for (int j = 0; j < students; j++)
        {
            std::cin >> scores[j];
            sum += scores[j];
        }
        avg = float(sum) / students;
        for (int j = 0; j < students; j++)
            if (avg < scores[j])
                count++;
        std::cout << (float(count) / students) * 100 << "%\n";
    }
}

#endif
