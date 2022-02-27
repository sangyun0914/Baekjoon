/**
 *  백준 10814: 나이순 정렬

문제
    온라인 저지에 가입한 사람들의 나이와 이름이 가입한 순서대로 주어진다.
    이때, 회원들을 나이가 증가하는 순으로, 나이가 같으면 먼저 가입한 사람이 앞에 오는 순서로 정렬하는 프로그램을 작성하시오.

입력
    첫째 줄에 온라인 저지 회원의 수 N이 주어진다. (1 ≤ N ≤ 100,000)
    둘째 줄부터 N개의 줄에는 각 회원의 나이와 이름이 공백으로 구분되어 주어진다.
    나이는 1보다 크거나 같으며, 200보다 작거나 같은 정수이고, 이름은 알파벳 대소문자로 이루어져 있고, 길이가 100보다 작거나 같은 문자열이다.
    입력은 가입한 순서로 주어진다.

출력
    첫째 줄부터 총 N개의 줄에 걸쳐 온라인 저지 회원을 나이 순, 나이가 같으면 가입한 순으로 한 줄에 한 명씩 나이와 이름을 공백으로 구분해 출력한다.

 *  https://www.acmicpc.net/problem/10814
**/

#include <iostream>
#include <algorithm>

using std::cin;
using std::string;

struct person
{
    int age;
    string name;
};

bool sorting(person A, person B)
{
    return A.age < B.age;
}

int main()
{
    int N, age;
    string name;
    cin >> N;
    person members[N];

    for (int i = 0; i < N; i++)
    {

        cin >> age;
        cin >> name;
        members[i].age = age;
        members[i].name = name;
    }

    std::stable_sort(members, members + N, sorting);

    for (auto x : members)
        std::cout << x.age << " " << x.name << "\n";

    return 0;
}

#if 1 // Merge Sort

#include <stdio.h>

typedef struct s_member
{
    int age;
    int order;
    char name[101]; // null 문자까지 고려해서 101개여야 함
} t_member;

t_member g_temp[100000]; //원본 배열 정렬할 때 잠시 쓰는 배열
//이거 없이 원본 배열만 써도 되지만 연산량이 늘어남

void merge_sort(void *arr, int left, int right)
{
    t_member *mb; //이 문제 풀기 위해 기본 merge sort 함수 구조를 살짝 변경
    int mid, l, r, k, a;

    mb = (t_member *)arr;     // t_member* 변수도 변경 요소 중 하나
    mid = (left + right) / 2; //분할하는 기준점
    l = left;                 //계속 왼쪽으로 이동하는 색인
    r = mid + 1;
    k = left; //정렬한 데이터가 들어가는 g_temp의 색인으로 쓰임

    while (l <= mid && r <= right)
    {
        if (mb[l].age == mb[r].age)
        { //나이가 같으면 순번으로 따진다
            g_temp[k++] = mb[l].order < mb[r].order ? mb[l++] : mb[r++];
        }
        else
        { //나이가 다르면 나이 오름차순으로 정렬
            g_temp[k++] = mb[l].age < mb[r].age ? mb[l++] : mb[r++];
        }
    } //앞 색인의 나이가 뒷 색인의 나이보다 이하면 정렬한 데이터가 들어가는 temp에 앞 색인 값이 들어감

    if (l > mid)
    {
        for (a = r; a <= right; ++a)
        {
            g_temp[k++] = mb[a];
        } //왼쪽 색인이 기준점까지 넘어오면 남은 mb 배열의 요소를 temp에 일단 넘김
    }
    else
    { //왼쪽 색인이 기준점까지 못 왔다는 오른쪽 색인 값들이 temp로 넘어갔다는 것
        for (a = l; a <= mid; ++a)
        {
            g_temp[k++] = mb[a];
        }
    } //그럼 남은 왼쪽 색인들이 기준점에 도달할 때까지의 값들을 temp 뒷부분에 넣어줘야 함
    for (a = left; a <= right; ++a)
    {
        mb[a] = g_temp[a];
    } // temp에 정리한 내용을 mb에 다시 옮김. 위의 while문부터 여기까지가 병합 부분
}

void my_merge(void *arr, int left, int right)
{ //원래 merge_sort()가 이 함수 기능도 포함했으나 제대로 작동 안 해서 my_merge() 따로 만듦
    int mid;

    if (left == right)
    {
        return;
    }                              //왼쪽, 오른쪽 색인이 같아지면 더 이상 분할도 없고 정리할 것도 없으니 반환
    mid = (left + right) / 2;      //분할하는 기준점
    my_merge(arr, left, mid);      //기준에서 왼쪽 배열 분할
    my_merge(arr, mid + 1, right); //오른쪽 배열 분할
    merge_sort(arr, left, right);  //분할한 배열을 정렬
}

int main(void)
{
    int n, i;
    t_member mb[100000]; //들어올 좌표 개수는 1 ~ 100000

    scanf("%d", &n);
    for (i = 0; i < n; ++i)
    {
        scanf("%d %s", &mb[i].age, mb[i].name);
        mb[i].order = i; //들어온 순서 기록
    }                    //들어온 인자 값 다 넣어줌

    my_merge(mb, 0, n - 1);
    //여기서 나이를 우선 순위로, 나이가 같으면 들어온 순서 기준으로 오름차순 정렬

    for (i = 0; i < n; ++i)
    {
        printf("%d %s\n", mb[i].age, mb[i].name);
    }

    return 0;
}

#endif