#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int answer = 0;
	for (int i = 1;i <= n;i++) {
		//2��° �� 3��°�� ���̿� 1��°�� 2��°�� ���̰� ������ ��
		//1��°�� ���� %10 2��°�� (����/10)%10 3��°�� ���� /100
		if (i < 100) {
			answer++;
		}
		else if (((i / 10) % 10) - (i % 10) == (i / 100) - ((i / 10) % 10)) {
			answer++;
		}
	}
	cout << answer << endl;
}