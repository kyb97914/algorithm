#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int w[10][10];
int main() {
	int n;
	cin >> n;
	vector<int> arr(n);
	int min = 9999999;
	for (int i = 0;i < n;i++) {
		arr[i] = i;
	}
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			cin >> w[i][j];
		}
	}
	vector<int> temp(n);
	do {
		//이제 여기서 외판 비용을 정한뒤 더해버리기 
		/*
		0,1,2,3 예시로 들면
		0 --> 1 + 1 --> 2 + 2-->3 하면됨

		*/
		if (arr[0] != 0)
			break;
		int answer = 0;
		bool ok = true;
		for (int i = 0;i < n- 1;i++) {
			if (w[arr[i]][arr[i + 1]] == 0)
				ok = false;
			else
				answer += w[arr[i]][arr[i + 1]];
		}
		if (ok && w[arr[n - 1]][arr[0]] != 0) {
			answer += w[arr[n - 1]][arr[0]];
			if (min > answer) {
				min = answer;
			}
		}
		
	} 	while (next_permutation(arr.begin()+1, arr.end()));
	cout << min << endl;

}