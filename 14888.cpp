#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector <int> arr(n);
	for (int i = 0;i < n;i++) {
		cin >> arr[i];
	}
	vector<int> cal;
	for (int i = 0;i < 4;i++) {
		int temp;
		cin >> temp;
		for (int j = 0;j < temp;j++) {
			cal.push_back(i);
		}
	}
	int max = -2147483647;
	int min = +2147483647;
	do {
		int answer = arr[0];
		for (int i = 0;i < n - 1;i++) {
			if (cal[i] == 0) {
				answer += arr[i + 1];
			}
			else if (cal[i] == 1) {
				answer -= arr[i + 1];
			}
			else if (cal[i] == 2) {
				answer = answer * arr[i + 1];
			}
			else {
				answer = answer / arr[i + 1];
			}
		}
		if (answer > max) {
			max = answer;
		}
		if (answer < min) {
			min = answer;
		}
	} while (next_permutation(cal.begin(), cal.end()));
	cout << max << endl;
	cout << min << endl;
}


/*
* n���� ���� �̷���� ������ �־��� ���� ���̿� ���� ���� �� �ִ� N-1���� �����ڰ� �־��� 
* ���� �����̿� �����ڸ� �־ ������ �����
* �־��� ���� ������ �ٲٸ� �ȵ�
* ���� ����� ������ �켱 ���� �����ϰ� �տ��� ���� ���� �������� ���� ���������θ� ���� ���Ѵ� ������ ����� ���� ���� C++14�� ������ ������.
* 
* 
*/