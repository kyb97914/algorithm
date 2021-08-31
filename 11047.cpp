/*
* 준규가 가지고 있는 동전은 총 N종류이고 각각의 동전을 매우 많이 가지고 있다.
* 동전을 적절히 사용해서 그 가치의 합을 K로 만들려고 한다. 이때 필요한 동전 개수의 최소값을 구하는 프로그램을 작성하시오
* 
* 입력
* 첫째 줄에 N과 K가 주어진다.
* 둘째 줄 부터 N개의 줄에 동전의 가치 Ai가 오름차 순으로 주어진다.
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