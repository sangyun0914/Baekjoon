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

#if 0 // Vector

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compareWith(string a, string b)
{
    if (a.length() == b.length())
        return a < b;
    return a.length() < b.length();
}

int main()
{
    int N;
    vector<string> vec;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        string str;
        cin >> str;
        if (find(vec.begin(), vec.end(), str) == vec.end())
            vec.push_back(str);
    }
    sort(vec.begin(), vec.end(), compareWith);

    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << '\n';
}

#endif

#if 1 // Merge Sort

#include <stdio.h>
#include <string.h>

typedef struct
{
    char string[51];
    int length;
} str;

str sorted[20001];
str arr[20001];

void merge(str arr[], int start, int mid, int last)
{
    int i, j, k;
    i = start;
    j = mid + 1;
    k = start;
    while (i <= mid && j <= last)
    {
        if (arr[i].length < arr[j].length)
            sorted[k++] = arr[i++];
        else if (arr[i].length > arr[j].length)
            sorted[k++] = arr[j++];
        else
        {
            if (strcmp(arr[i].string, arr[j].string) > 0)
                sorted[k++] = arr[j++];

            else
                sorted[k++] = arr[i++];
        }
    }
    if (i <= mid)
    {
        while (i <= mid)
            sorted[k++] = arr[i++];
    }
    else
    {
        while (j <= last)
            sorted[k++] = arr[j++];
    }
    for (i = start; i <= last; i++)
        arr[i] = sorted[i];
}

void merge_sort(str arr[], int start, int last)
{
    int mid;
    if (start < last)
    {
        mid = (start + last) / 2;
        merge_sort(arr, start, mid);
        merge_sort(arr, mid + 1, last);
        merge(arr, start, mid, last);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", arr[i].string);
        arr[i].length = strlen(arr[i].string);
    }

    merge_sort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        if (strcmp(arr[i].string, arr[i + 1].string) != 0)
            printf("%s\n", arr[i].string);
    }

    return 0;
}

#endif

#if 0 // QuickSort

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int len;
    char str[51];
} Word;

int compare(const void *first, const void *second)
{
    Word *a = (Word *)first;
    Word *b = (Word *)second;

    if (a->len < b->len)
        return -1;
    else if (a->len > b->len)
        return 1;
    else if (a->len == b->len)
    {
        if (strcmp(a->str, b->str) < 0)
            return -1;
        else
            return 1;
    }
    return 0;
}

int main()
{
    int i, j, n;
    Word *text;

    scanf("%d", &n);

    text = (Word *)calloc(n + 1, sizeof(Word));

    for (i = 0; i < n; i++)
    {
        scanf(" %s", text[i].str);
        text[i].len = strlen(text[i].str);

        /*중복 제거*/
        for (j = 0; j < i; j++)
        {
            if (strcmp(text[i].str, text[j].str) == 0)
            {
                i -= 1;
                n -= 1;
                break;
            }
        }
    }

    qsort(text, n, sizeof(text[0]), compare);

    for (i = 0; i < n; i++)
    {
        printf("%s\n", text[i].str);
    }

    return 0;
}

#endif

#if 0 // Timeout

#include <iostream>

int main()
{
    int num, place, dupCount = 0;
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
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

#endif