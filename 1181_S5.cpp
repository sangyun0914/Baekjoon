/**
 *  백준 1181: 단어 정렬

문제
    알파벳 소문자로 이루어진 N개의 단어가 들어오면 아래와 같은 조건에 따라 정렬하는 프로그램을 작성하시오.
    1. 길이가 짧은 것부터
    2. 길이가 같으면 사전 순으로

입력
    첫째 줄에 단어의 개수 N이 주어진다. (1 ≤ N ≤ 20,000)
    둘째 줄부터 N개의 줄에 걸쳐 알파벳 소문자로 이루어진 단어가 한 줄에 하나씩 주어진다.
    주어지는 문자열의 길이는 50을 넘지 않는다.

출력
    조건에 따라 정렬하여 단어들을 출력한다. 단, 같은 단어가 여러 번 입력된 경우에는 한 번씩만 출력한다.

 *  https://www.acmicpc.net/problem/1181
**/

#include <iostream>

int main()
{
    int num, place, dupCount = 0;
    std::cin >> num;
    std::cin.ignore();
    std::string array[num];
    getline(std::cin, array[0]);
    std::string input;

    for (int i = 1; i < num; i++) // Iterate through all words
    {
        getline(std::cin, input);
        if (input.length() == array[0].length())
        {
            if (input < array[0])
                place = 0;
        }
        else if (input.length() == array[i - dupCount - 1].length())
        {
            if (input > array[i - dupCount - 1])
                place = i - dupCount;
        }

        if (input.length() < array[0].length()) // If among shortest
            place = 0;
        else if (input.length() > array[i - dupCount - 1].length()) // If among longest
            place = i - dupCount;
        else // In between
        {
            for (int j = 0; j < i - dupCount; j++)
            {
                if (input.length() > array[j].length() && input.length() < array[j + 1].length())
                {
                    place = j + 1;
                    break;
                }
                else if (input.length() == array[j].length())
                {
                    if (input < array[j])
                    {
                        place = j;
                        break;
                    }
                    if (input > array[j] && input.length() < array[j + 1].length())
                    {
                        place = j + 1;
                        break;
                    }
                    if (input.length() == array[j + 1].length())
                    {
                        if (input > array[j] && input < array[j + 1])
                        {
                            place = j + 1;
                            break;
                        }
                    }
                    if (input == array[j])
                    {
                        place = j;
                        dupCount++;
                        break;
                    }
                }
            }
        }
        if (input == array[place])
            continue;

        for (int j = i - dupCount; j > place; j--)
            array[j] = array[j - 1];
        array[place] = input;
    }

    for (int i = 0; i < num - dupCount; i++)
        std::cout << array[i] << "\n";
}