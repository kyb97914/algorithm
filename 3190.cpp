#include <iostream>
#include <vector>
using namespace std;


struct direction {
	int time;
	char direct;//L이 왼쪽 R이 오른쪽
};
struct xy {
	int x;
	int y;
};
bool apple[100][100];
direction dir[100];
int mx[4] = { -1,0,1,0 };
int my[4] = { 0,-1,0,1 };
int main() {
	int N;//보드의 크기
	int K; // 사과의 갯수
	cin >> N >> K;
	int x, y;
	for (int i = 0;i < K;i++) {
		cin >> x >> y;
		apple[x-1][y-1] =true ;
	}
	int L;//뱀의 방향 변환 횟수
	cin >> L;
	for (int i = 0;i < L;i++) {
		cin >> dir[i].time >> dir[i].direct;
	}
	int time = 0;
	int head = 3;//0:북(-1,0) 1: 서(0,-1) 2: 남(1,0) 3:동(0,1)
	vector<xy> snake;
	xy temp;
	temp.x = 0;
	temp.y = 0;
	snake.push_back(temp);
	int dir_index = 0;
	while (1) {
		time++;
		temp.x += mx[head];
		temp.y += my[head];
			
		//늘리기 완료
		//벽에 닿았는지 몸에 닿았는지 체크
		
		if (temp.x == N || temp.y == N || temp.x == -1 || temp.y == -1) {
			cout << time;
			return 0;
		}
		for (int i = 0;i < snake.size();i++) {
			if (temp.x == snake[i].x&&temp.y==snake[i].y) {
				cout << time;
				return 0;
			}
		}
		//사과가 있는지 체크
		if (apple[temp.x][temp.y] == true) {
			snake.push_back(temp);
			apple[temp.x][temp.y] = false;
		}
		else {
			snake.push_back(temp);
			snake.erase(snake.begin());
		}
		//사과가 없으면 몸길이 줄이기 vector값없애주기
		//방향 전환 해주기 
		if (time == dir[dir_index].time) {
			if (dir[dir_index].direct == 'L') {
				head=(head+1)%4;
			}
			else {
				if (head == 0) {
					head = 3;
				}
				else {
					head--;
				}
			}
			dir_index++;
		}
	}
}

/*
사과를 먹으면 뱀 길이가 늘어남
자기 자신의 몸과 부딪히거나 벽에 닿으면 끝남
0,0이 시작 위치
0,1이 위치하는 방향
움직이는데 다음과 같은 규칙을 가짐
1. 몸길이를 늘려 머리를 다음칸에 위치 시킴 q.push
2. 만약 이동한 칸에 사과가 있다면 그 칸에 있던 사과가 없어지고 꼬리는 움직이지않음 push만
3. 만약 이동한 칸에 사과가 없다면 몸길이를 줄여서 꼬리가 위치한 칸을 비워준다. pop
선입 선출 뱀을 queue로 가능

*/