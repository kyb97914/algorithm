/*
ATM이 1대 밖에 없으여 ATM앞에 N명으 ㅣ사람들이 줄을 서있고 1번부터 N번까지 번호가 매겨져 잇따.
i번 사람이 돈을 인출하는데 걸리는 시간은 Pi분이다.



*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main() {

	int n;
	cin >> n;
	vector<int> p(n);
	for (int i = 0;i < n;i++) {
		cin >> p[i];
	}

	sort(p.begin(), p.end());
	int sum = 0;
	int ans = 0;
	for (int i = 0;i < n;i++) {
		sum += p[i];
		ans += sum;
	}
	cout << ans << "\n";

}