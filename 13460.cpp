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
				//�������� �̵� red_x�� �׻��·� �� �� red_y ���� ����� ������ ã���� ��
				//���� x�� ��ǥ�� blue�� red�� ���� ����� y�� ��ǥ�� ���� ���� ���� �̵�
				if (b.x == r.x) {

					if (b.y < r.y) {
						//Red�� y��ǥ�� ū ��� blue���� �̵�
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
						//Blue�� y��ǥ�� ū ��� Red ���� �̵�
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
					//���� red blue �̵�
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
				//���������� �̵� red_x�� �׻��·� �� �� red_y���� ����� �����ʿ� �ִ� #�̳� 0�� ã���� ��
				//���� x�� ��ǥ�� blue�� red�� ���� ����� y�� ��ǥ�� ū ���� ���� �̵�
				if (b.x == r.x) {
					if (b.y < r.y) {
						//Blue�� y��ǥ�� ū ��� Red ���� �̵�
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
						//Red�� y��ǥ�� ū ��� blue���� �̵�
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
					//���� red blue �̵�
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
			//�������� �̵� x��ǥ �̵� 
				if (b.y == r.y) {
					if (b.x < r.x) {
						//Red�� y��ǥ�� ū ��� blue���� �̵�
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
						//Blue�� y��ǥ�� ū ��� Red ���� �̵�
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
					//���� red blue �̵�
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
						//Blue�� y��ǥ�� ū ��� Red ���� �̵�
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
						//Red�� y��ǥ�� ū ��� blue���� �̵�
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
					//���� red blue �̵�
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
						//���� red_temp�� �̵��� �Ÿ���ŭ dist�� ���� ��� ��
						//check�� ��������
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