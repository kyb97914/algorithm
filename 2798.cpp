#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	vector<int> arr(n);
	for (int i = 0;i < n;i++) {
		cin >> arr[i];
	}
	int max = 0;
	for (int i = 0;i < n;i++) {
		for (int j = 1;j < n;j++) {
			for (int k = 2; k < n;k++) {
				if (i == j || j == k || k == i) {
				
				}
				else {
					int temp = arr[i] + arr[j] + arr[k];
					if (temp > max && temp <= m) {
						max = temp;
					}
				}
			}
		}
	}
	cout << max << endl;
}