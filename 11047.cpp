/*
* �ر԰� ������ �ִ� ������ �� N�����̰� ������ ������ �ſ� ���� ������ �ִ�.
* ������ ������ ����ؼ� �� ��ġ�� ���� K�� ������� �Ѵ�. �̶� �ʿ��� ���� ������ �ּҰ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�
* 
* �Է�
* ù° �ٿ� N�� K�� �־�����.
* ��° �� ���� N���� �ٿ� ������ ��ġ Ai�� ������ ������ �־�����.
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int n,k,temp;
	int answer = 0;
	vector<int> arr;
	cin >> n>>k;
	for (int i = 0;i < n;i++) {
		int temp;
		cin >> temp;
		arr.push_back(temp);
	}
	sort(arr.begin(), arr.end(),greater<>());
	for (int i = 0;i < n;i++)
	{
		if (k == 0) {
			break;
		}
		answer += k / arr[i];
		k = k % arr[i];
	}
	cout << answer << endl;
	return 0;
}