#include <iostream>
#include <vector>
using namespace std;


struct direction {
	int time;
	char direct;//L�� ���� R�� ������
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
	int N;//������ ũ��
	int K; // ����� ����
	cin >> N >> K;
	int x, y;
	for (int i = 0;i < K;i++) {
		cin >> x >> y;
		apple[x-1][y-1] =true ;
	}
	int L;//���� ���� ��ȯ Ƚ��
	cin >> L;
	for (int i = 0;i < L;i++) {
		cin >> dir[i].time >> dir[i].direct;
	}
	int time = 0;
	int head = 3;//0:��(-1,0) 1: ��(0,-1) 2: ��(1,0) 3:��(0,1)
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
			
		//�ø��� �Ϸ�
		//���� ��Ҵ��� ���� ��Ҵ��� üũ
		
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
		//����� �ִ��� üũ
		if (apple[temp.x][temp.y] == true) {
			snake.push_back(temp);
			apple[temp.x][temp.y] = false;
		}
		else {
			snake.push_back(temp);
			snake.erase(snake.begin());
		}
		//����� ������ ������ ���̱� vector�������ֱ�
		//���� ��ȯ ���ֱ� 
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
����� ������ �� ���̰� �þ
�ڱ� �ڽ��� ���� �ε����ų� ���� ������ ����
0,0�� ���� ��ġ
0,1�� ��ġ�ϴ� ����
�����̴µ� ������ ���� ��Ģ�� ����
1. �����̸� �÷� �Ӹ��� ����ĭ�� ��ġ ��Ŵ q.push
2. ���� �̵��� ĭ�� ����� �ִٸ� �� ĭ�� �ִ� ����� �������� ������ ������������ push��
3. ���� �̵��� ĭ�� ����� ���ٸ� �����̸� �ٿ��� ������ ��ġ�� ĭ�� ����ش�. pop
���� ���� ���� queue�� ����

*/