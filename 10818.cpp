#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int calcuate(vector<int> arr) {
	int answer = 0;
	for (int i = 0;i < arr.size()-1;i++) {
		answer = answer + abs(arr[i + 1] - arr[i]);
	}
	return answer;
}

int main() {
	int n;
	cin>>n;
	vector<int> arr(n);
	for (int i = 0;i < n;i++) {
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());
	int answer = 0;
	do {

		int temp = calcuate(arr);
		if (answer < temp) {
			answer = temp;
		}
	} 	while (next_permutation(arr.begin(), arr.end()));


	cout << answer << endl;
}