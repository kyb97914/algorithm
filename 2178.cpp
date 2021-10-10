// https://www.acmicpc.net/problem/2178

#include <iostream>
#include <vector>
#include<cstdio>
#include <queue>

using namespace std;

int n, m;
int arr[100][100];
int dist[100][100];
bool check[100][100];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
struct xy {
    int x;
    int y;
};

int main() {
    scanf_s("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf_s("%1d", &arr[i][j]);
        }
    }
    queue<xy> q;
    xy temp;
    temp.x = 0;
    temp.y = 0;
    q.push(temp);
    dist[0][0] = 1;
    while (!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        q.pop();
        for (int i = 0;i < 4;i++) {
            int m_x = x + dx[i];
            int m_y = y + dy[i];
            if (0 <= m_x && 0 <= m_y && m_x < n && m_y < m) {
                if (check[m_x][m_y] == false && arr[m_x][m_y] == 1) {
                    xy temp;
                    temp.x = m_x;
                    temp.y = m_y;
                    q.push(temp);
                    dist[m_x][m_y] = dist[x][y]+1;
                    check[m_x][m_y] = true;
                }
            }
        }
    }

    cout << dist[n - 1][m - 1] << endl;
	return 0;
}