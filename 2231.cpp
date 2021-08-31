#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	int sum;
	int temp;
	for (int i = 1;i < n;++i) {
		temp = i;
		sum = i;
		while (temp) {
			sum += temp % 10;
			temp = temp / 10;
		}
		if (sum == n) {
			cout << i << endl;
			return 0;
		}
	}
	cout << "0" << endl;
	return 0;
}