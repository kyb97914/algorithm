/*
ATM�� 1�� �ۿ� ������ ATM�տ� N���� �ӻ������ ���� ���ְ� 1������ N������ ��ȣ�� �Ű��� �յ�.
i�� ����� ���� �����ϴµ� �ɸ��� �ð��� Pi���̴�.



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