#include <iostream>
#include <queue>

using namespace std;

int mx[4] = { 0,0,-1,1 };
int my[4] = { -1,1,0,0 };
int dist[10][10];
bool check[10][10];
char arr[10][10];

struct xy {
	int x;
	int y;
};
int main() {
	xy blue;
	xy red;

	int N, M;
	cin >> N >> M;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'B') {
				blue.x = i;
				blue.y = j;
			}
			if (arr[i][j] == 'R') {
				red.x = i;
				red.y = j;
			}
		}
	}
	queue<xy> q_red;
	queue<xy> q_blue;
	check[red.x][red.y] = true;
	dist[red.x][red.y] = 0;
	q_red.push(red);
	q_blue.push(blue);
	int move_count = 0;
	while (!q_red.empty()) {
		xy r, b;
		r.x=q_red.front().x;
		r.y = q_red.front().y;
		b.x = q_blue.front().x;
		b.y = q_blue.front().y;
		q_red.pop();
		q_blue.pop();
		for (int i = 0;i < 4;i++) {
			xy red_temp, blue_temp;
			red_temp.x = r.x;
			red_temp.y = r.y;
			blue_temp.x = b.x;
			blue_temp.y = b.y;

			bool promise = true;
			if (i == 0) {
				//왼쪽으로 이동 red_x를 그상태로 둔 후 red_y 에서 가까운 왼쪽을 찾으면 됨
				//만약 x의 좌표가 blue와 red가 같은 경우라면 y의 좌표가 적은 구슬 부터 이동
				if (b.x == r.x) {

					if (b.y < r.y) {
						//Red의 y좌표가 큰 경우 blue부터 이동
						for (int j = b.y-1;j >= 0;j--) {
							if (arr[b.x][j] == '#') {
								blue_temp.y = j+1;
								red_temp.y = j + 2;
								break;
							}
							if (arr[b.x][j] == 'O') {
								promise = false;
								break;
							}
						}
					}
					else {
						//Blue의 y좌표가 큰 경우 Red 부터 이동
						for (int j = r.y - 1;j >= 0;j--) {
							if (arr[r.x][j] == '#') {
								red_temp.y = j+1;
								blue_temp.y = j + 2;
								break;
							}
							if (arr[r.x][j] == 'O') {
								promise = false;
								break;
							}
						}
					}
				}
				else {
					//각자 red blue 이동
					for (int j = r.y - 1;j >= 0;j--) {
						if (arr[r.x][j] == '#') {
							red_temp.y = j + 1;
							break;
						}
						if (arr[r.x][j] == 'O') {
							cout << dist[r.x][r.y] + 1;
							return 0;
						}
					}
					for (int j = b.y - 1;j >= 0;j--) {
						if (arr[b.x][j] == '#') {
							blue_temp.y = j + 1;
							break;
						}
						if (arr[b.x][j] == 'O') {
							promise = false;
							break;
						}
					}
				}
			}
			else if (i == 1) {
				//오른쪽으로 이동 red_x를 그상태루 둔 후 red_y에서 가까운 오른쪽에 있는 #이나 0를 찾으면 됨
				//만약 x의 좌표가 blue와 red가 같은 경우라면 y의 좌표가 큰 구슬 부터 이동
				if (b.x == r.x) {
					if (b.y < r.y) {
						//Blue의 y좌표가 큰 경우 Red 부터 이동
						for (int j = r.y+1 ;j<M;j++) {
							if (arr[r.x][j] == '#') {
								red_temp.y = j-1;
								blue_temp.y = j-2;
								break;
							}
							if (arr[r.x][j] == 'O') {
								promise = false;
								break;
							}
						}
					}
					else {
						//Red의 y좌표가 큰 경우 blue부터 이동
						for (int j = b.y + 1;j < M;j++) {
							if (arr[b.x][j] == '#') {
								blue_temp.y = j - 1;
								red_temp.y = j -2;
								break;
							}
							if (arr[b.x][j] == 'O') {
								promise = false;
								break;
							}
						}
						
					}
				}
				else {
					//각자 red blue 이동
					for (int j = r.y + 1;j < M;j++) {
						if (arr[r.x][j] == '#') {
							red_temp.y = j - 1;
							break;
						}
						if (arr[r.x][j] == 'O') {
							cout << dist[r.x][r.y] + 1;
							return 0;
						}
					}
					for (int j = b.y + 1;j < M;j++) {
						if (arr[b.x][j] == '#') {
							blue_temp.y = j - 1;
							break;
						}
						if (arr[b.x][j] == 'O') {
							promise = false;
							break;
						}
					}
				}
			}
			else if (i == 2) {
			//위쪽으로 이동 x좌표 이동 
				if (b.y == r.y) {
					if (b.x < r.x) {
						//Red의 y좌표가 큰 경우 blue부터 이동
						for (int j = b.x - 1;j >= 0;j--) {
							if (arr[j][b.y] == '#') {
								blue_temp.x = j + 1;
								red_temp.x = j + 2;
								break;
							}
							if (arr[j][b.y] == 'O') {
								promise = false;
								break;
							}
						}
					}
					else {
						//Blue의 y좌표가 큰 경우 Red 부터 이동
						for (int j = r.x - 1;j >= 0;j--) {
							if (arr[j][r.y] == '#') {
								red_temp.x = j + 1;
								blue_temp.x = j + 2;
								break;
							}
							if (arr[j][r.y] == 'O') {
								promise = false;
								break;
							}
						}
					}
				}
				else {
					//각자 red blue 이동
					for (int j = r.x - 1;j >= 0;j--) {
						if (arr[j][r.y] == '#') {
							red_temp.x = j + 1;
							break;
						}
						if (arr[j][r.y] == 'O') {
							cout << dist[r.x][r.y] + 1;
							return 0;
						}
					}
					for (int j = b.x - 1;j >= 0;j--) {
						if (arr[j][b.y] == '#') {
							blue_temp.x = j + 1;
							break;
						}
						if (arr[j][b.y] == 'O') {
							promise = false;
							break;
						}
					}
				}
			}
			else if (i == 3) {
				if (b.y == r.y) {
					if (b.x < r.x) {
						//Blue의 y좌표가 큰 경우 Red 부터 이동
						for (int j = r.x + 1;j < N;j++) {
							if (arr[j][r.y] == '#') {
								red_temp.x = j - 1;
								blue_temp.x = j - 2;
								break;
							}
							if (arr[j][r.y] == 'O') {
								promise = false;
								break;
							}
						}
					}
					else {
						//Red의 y좌표가 큰 경우 blue부터 이동
						for (int j = b.x + 1;j < N;j++) {
							if (arr[j][b.y] == '#') {
								blue_temp.x = j - 1;
								red_temp.x = j - 2;
								break;
							}
							if (arr[j][b.y] == 'O') {
								promise = false;
								break;
							}
						}

					}
				}
				else {
					//각자 red blue 이동
					for (int j = r.x + 1;j < N;j++) {
						if (arr[j][r.y] == '#') {
							red_temp.x = j - 1;
							break;
						}
						if (arr[j][r.y] == 'O') {
							cout << dist[r.x][r.y] + 1;
							return 0;
						}
					}
					for (int j = b.x + 1;j < N;j++) {
						if (arr[j][b.y] == '#') {
							blue_temp.x = j - 1;
							break;
						}
						if (arr[j][b.y] == 'O') {
							promise = false;
							break;
						}
					}
				}
			}
			if (0 <= red_temp.x && red_temp.x < N && 0 <= red_temp.y && red_temp.y < M) {
				if (check[red_temp.x][red_temp.y] == false) {
					if (promise==true) {
						//이제 red_temp가 이동한 거리만큼 dist를 더해 줘야 함
						//check도 마찬가지
						if (i == 0) {
							for (int j = r.y - 1;j >= red_temp.y;j--) {
								dist[red_temp.x][j] = dist[r.x][r.y] + 1;
								check[red_temp.x][j] = true;
							}
						}
						else if (i == 1) {
							for (int j = r.y+1;j <= red_temp.y;j++) {
								dist[red_temp.x][j] = dist[r.x][r.y] + 1;
								check[red_temp.x][j] = true;
							}
						}
						else if (i == 2) {
							for (int j = r.x - 1;j >= red_temp.x;j--) {
								dist[j][red_temp.y] = dist[r.x][r.y] + 1;
								check[j][red_temp.y] = true;
							}
						}
						else if (i == 3) {
							for (int j = r.x + 1;j <= red_temp.x;j++) {
								dist[j][red_temp.y] = dist[r.x][r.y] + 1;
								check[j][red_temp.y] = true;
							}
						}
						q_red.push(red_temp);
						q_blue.push(blue_temp);
					}
				}
			}
		}
	
	}
	

}