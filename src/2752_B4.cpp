/**
 *  백준 2752: 세수정렬

문제
    동규는 세수를 하다가 정렬이 하고싶어졌다.
    숫자 세 개를 생각한 뒤에, 이를 오름차순으로 정렬하고 싶어 졌다.
    숫자 세 개가 주어졌을 때, 가장 작은 수, 그 다음 수, 가장 큰 수를 출력하는 프로그램을 작성하시오.

입력
    숫자 세 개가 주어진다. 이 숫자는 1보다 크거나 같고, 1,000,000보다 작거나 같다. 이 숫자는 모두 다르다.

출력
    제일 작은 수, 그 다음 수, 제일 큰 수를 차례대로 출력한다.

 *  https://www.acmicpc.net/problem/2752
**/

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int num;
    std::vector<int> v;
    for (int i = 0; i < 3; i++)
    {
        std::cin >> num;
        v.push_back(num);
    }
    sort(v.begin(), v.end());
    for (auto x : v)
        std::cout << x << " ";
}

#if 0 // Using BubbleSort

#include <iostream>
using namespace std;

int arr[3];

void bubbleSort()
{
    int tmp;
    for (int i = 0; i < 3; i++)
    {
        for (int j = i + 1; j < 3; j++)
        {
            if (arr[i] > arr[j])
            {
                tmp = arr[j];
                arr[j] = arr[i];
                arr[i] = tmp;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 3; i++)
        cin >> arr[i];

    bubbleSort();

    for (int i = 0; i < 3; i++)
        cout << arr[i] << ' ';

    return 0;
}

#endif

#if 0 // Manual Sort

#include <iostream>
using namespace std;

int main()
{
    int a, b, c;

    cin >> a >> b >> c;
    if (a > b && a > c)
    {
        if (b > c)
            cout << c << " " << b << " " << a;
        else
            cout << b << " " << c << " " << a;
    }
    else if (b > a && b > c)
    {
        if (a > c)
            cout << c << " " << a << " " << b;
        else
            cout << a << " " << c << " " << b;
    }
    else if (c > a && c > b)
    {
        if (a > b)
            cout << b << " " << a << " " << c;
        else
            cout << a << " " << b << " " << c;
    }
    return 0;
}

#endif