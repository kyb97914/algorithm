#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n;

	while (1) {
		cin >> n;
		if (n == 0) {
			break;
		}
		else {
			vector<int> arr(n);
			for (int i = 0;i < n;i++) {
				cin >> arr[i];
			}
			vector<int> temp;
			for (int i = 0; i < n - 6; i++) {
				temp.push_back(0);
			}
			for (int i = 0; i < 6; i++) {
				temp.push_back(1);
			}
			do {
				for (int i = 0;i < n;i++) {
					if (temp[i] == 1) {
						cout << arr[i] << " ";
					}
				}
				cout << endl;
			} while (next_permutation(temp.begin(), temp.end()));
		}
		cout << endl;
	}
}
/*
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n;

	while (1) {
		cin >> n;
		if (n == 0) {
			break;
		}
		else {
			vector<int> arr(n);
			for (int i = 0;i < n;i++) {
				cin >> arr[i];
			}
			vector<int> temp(n);
			for (int i = 0;i < 6;i++) {
				temp[i] = 1;
			}
			sort(temp.begin(), temp.end());
			do {
				for (int i = 0;i < n;i++) {
					if (temp[i] == 1) {
						cout << arr[i] << " ";
					}
				}
				cout << endl;
			} while (next_permutation(temp.begin(), temp.end()));
		}
		cout << endl;
	}
}
*/