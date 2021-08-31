#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int n;
	cin >> n;
	int arr[21][21];
	int copy[21][21];
	for (int i = 0;i < n;i++) {
		string line;
		cin >> line;
		for (int j = 0;j < n;j++) {
			if (line[j] == 'T') {
				arr[i][j] = 1;
				copy[i][j] = 1;
			}
		}
	}
}