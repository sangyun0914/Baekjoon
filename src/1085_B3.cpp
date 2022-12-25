/**
 *  백준 1085: 직사각형에서 탈출

문제
    한수는 지금 (x, y)에 있다. 직사각형은 각 변이 좌표축에 평행하고, 왼쪽 아래 꼭짓점은 (0, 0), 오른쪽 위 꼭짓점은 (w, h)에 있다. 직사각형의 경계선까지 가는 거리의 최솟값을 구하는 프로그램을 작성하시오.

입력
    첫째 줄에 x, y, w, h가 주어진다.

출력
    첫째 줄에 문제의 정답을 출력한다.

 *  https://www.acmicpc.net/problem/1085
**/

#include <iostream>

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    int x, y, w, h, min;
    std::cin >> x >> y >> w >> h;

    min = x < y ? x : y;
    min = min < w - x ? min : w - x;
    min = min < h - y ? min : h - y;

    std::cout << min;
}