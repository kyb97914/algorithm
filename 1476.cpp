#include <iostream>
#include <vector>

using namespace std;

int main() {

	int e, s, m;
	cin >> e >> s >> m;
	int num_e = 1;
	int num_s = 1;
	int num_m = 1;
	int answer = 1;

	while (1) {
		if (num_e == e && num_s == s && num_m == m) {
			break;
		}
		num_e++;
		num_s++;
		num_m++;
		if (num_e == 16) {
			num_e = 1;
		}
		if (num_s == 29) {
			num_s = 1;
		}
		if (num_m == 20) {
			num_m = 1;
		}
		answer++;
	}
	cout << answer << endl;
}

/*

*/