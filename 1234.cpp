#include<iostream>

using namespace std;
int main() {
	cout << (1 << 10) << endl;
	for (int i = 1; i < 1 << 10;i++) {
		int score = 0;
		cout << "i :" << i<<" 1�� ������� ���?  : ";
		for (int j = 0;j < 10;j++) {
			cout << (1 << j) << endl;
			if (i & (1 << j)) {
				cout << j << " ";
			}
		}
		cout << endl;
	}
}