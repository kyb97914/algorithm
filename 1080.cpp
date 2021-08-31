/*
0과 1로만 이루어진 행렬 A와 B가 존재 행렬 A를 행렬 B로 바꾸는 데 필요한 연산의 횟수의 최소 값ㅇ르 구하는 프로그램을 작성하시오


*/

#include <iostream>
#include <algorithm>
using namespace std;
 
int a[50][50];
int b[50][50];
 
void reverse(int y, int x) {
    for (int i = y - 1; i <= y + 1; i++) {
        for (int j = x - 1; j <= x + 1; j++) {
            a[i][j] = 1 - a[i][j];
        }
    }
}
int main()
{
    //입력
    int n, m; scanf_s("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf_s("%1d", &a[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf_s("%1d", &b[i][j]);
        }
    }
    int ans = 0;
    for (int i = 0; i < n - 2; i++) {
        for (int j = 0; j < m - 2; j++) {
            if (a[i][j] != b[i][j]) {
                ans++;
                reverse(i + 1, j + 1);
            }
        }
    }
 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] != b[i][j]) {
                printf("%d", -1);
                return 0;
            }
        }
    }
    printf("%d", ans);
    return 0;
}