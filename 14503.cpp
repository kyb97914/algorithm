#include <iostream>
#include <vector>

using namespace std;

int arr[50][50];
int main() {
	int n, m;
	cin >> n >> m;
	int r, c, d;
	cin >> r >> c >> d;
	int cnt = 0;
	//d�� 0�϶� �� 1�϶� �� 2�϶� �� 3�϶� ��
	for (int i = 0;i < n;i++) {
		for (int j = 0;j<m;j++){
			cin >> arr[i][j];
		}
	}
	while (1) {
		if (arr[r][c] == 0) {
			arr[r][c] = 2;
			cnt++;
		}

		if (arr[r - 1][c] != 0 && arr[r + 1][c] != 0 && arr[r][c + 1] != 0 && arr[r][c - 1] != 0) {
		
			if (d == 0) {
				if (arr[r + 1][c] != 1) {
					r = r + 1;
				}
				else {
					break;
				}
			}
			else if (d == 1) {
				if (arr[r][c - 1] != 1) {
					c = c - 1;
				}
				else {
					break;
				}
			}
			else if (d == 2) {
				if (arr[r - 1][c] != 1) {
					r = r - 1;
				}
				else {
					break;
				}
			}
			else {
				if (arr[r][c + 1] != 1) {
					c = c + 1;
				}
				else {
					break;
				}
			}
		}
		else {
		
			if (d == 0) {
				//������ �ٶ󺸰� ������
				if (arr[r][c - 1] == 0) {
					c--;

				}
				d = 3;
			}
			else if (d == 1) {
				//������ �ٶ󺸰� ���� ��
				if (arr[r - 1][c] == 0) {
					r--;

				}
				d = 0;
			}
			else if (d == 2) {
				//������ �ٶ󺸰� ���� ��
				if (arr[r][c + 1] == 0) {
					c++;

				}
				d = 1;
			}
			else {		//������ �ٶ󺸰� ���� ��
				if (arr[r + 1][c] == 0) {
					r++;

				}
				d = 2;
			}
		}
		
	}
	cout << cnt << endl;
}