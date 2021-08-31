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
	//d가 0일때 북 1일때 동 2일때 남 3일때 서
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
				//북쪽을 바라보고 있을때
				if (arr[r][c - 1] == 0) {
					c--;

				}
				d = 3;
			}
			else if (d == 1) {
				//동쪽을 바라보고 있을 때
				if (arr[r - 1][c] == 0) {
					r--;

				}
				d = 0;
			}
			else if (d == 2) {
				//남쪽을 바라보고 있을 때
				if (arr[r][c + 1] == 0) {
					c++;

				}
				d = 1;
			}
			else {		//서쪽을 바라보고 있을 때
				if (arr[r + 1][c] == 0) {
					r++;

				}
				d = 2;
			}
		}
		
	}
	cout << cnt << endl;
}