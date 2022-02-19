/**
 *  백준 2609: 최대공약수와 최소공배수

문제
    두 개의 자연수를 입력받아 최대 공약수와 최소 공배수를 출력하는 프로그램을 작성하시오.

입력
    첫째 줄에는 두 개의 자연수가 주어진다. 이 둘은 10,000이하의 자연수이며 사이에 한 칸의 공백이 주어진다.

출력
    첫째 줄에는 입력으로 주어진 두 수의 최대공약수를, 둘째 줄에는 입력으로 주어진 두 수의 최소 공배수를 출력한다.

 *  https://www.acmicpc.net/problem/2609
**/

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int num1, num2, GCD, LCM;
    std::cin >> num1 >> num2;
    std::vector<int> v1, v2;

    for (int i = 1; i <= num1; i++)
        if (num1 % i == 0)
            if (find(v1.begin(), v1.end(), i) == v1.end())
                v1.push_back(i);

    for (int i = 1; i <= num2; i++)
        if (num2 % i == 0)
            if (find(v2.begin(), v2.end(), i) == v2.end())
                v2.push_back(i);

    for (int i = 0; i < v1.size(); i++)
        if (find(v2.begin(), v2.end(), v1[i]) != v2.end())
            GCD = v1[i];

    LCM = (num1 * num2) / GCD;
    std::cout << GCD << "\n"
              << LCM;
}

#if 0 // Better using Euclidean algorithm

#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    int c = a % b;
    while (c != 0)
    {
        a = b;
        b = c;
        c = a % b;
    }
    return b;
}

int lcm(int a, int b)
{
    return (a * b) / gcd(a, b);
}

int main()
{
    int n1, n2;
    cin >> n1 >> n2;
    cout << gcd(n1, n2) << "\n"
         << lcm(n1, n2);
}

#endif

#if 0 // Using Euclidean Recursion

#include <stdio.h>
int gcd2(int A, int B)
{
    if (B == 0)
        return A;
    gcd2(B, A % B);
}
int main()
{
    int A, B;
    scanf("%d %d", &A, &B);
    int num = gcd2(A, B);
    printf("%d\n%d", num, A * B / num);
}

#endif