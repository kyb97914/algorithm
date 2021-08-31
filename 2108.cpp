#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	int n;
	cin >> n;
	vector <int> arr(n);
	float sum = 0;
	int temp = 0;
	int max = 0;
	vector <int> arr2(8001, 0);
	for (int i = 0;i < n;i++) {
		cin>>arr[i];
		sum += arr[i];
		temp = (arr[i] <= 0) ? abs(arr[i]) : arr[i] + 4000;
		arr2[temp]++;
		if (arr2[temp] > max) {
			max = arr2[temp];
		}
	}
	int mode = 0;
	bool isSecond = false;
	for (int i = -4000; i < 4001; i++) {
		temp = i <= 0 ? abs(i) : i + 4000;
		if (arr2[temp] == max) {
			mode = i;
			if (isSecond)
				break;
			isSecond = true;
		}
	}
	sort(arr.begin(), arr.end());
	cout << round(sum / n)<<endl;
	cout << arr[round(n / 2)] << endl;
	cout << mode << endl;
	int min = arr[0];
	max = arr[arr.size() - 1];
	cout << max - min << '\n';

}