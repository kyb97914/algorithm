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
* n개의 수로 이루어진 수열이 주어짐 숫자 사이에 끼워 넣을 수 있는 N-1개의 연산자가 주어짐 
* 수와 수사이에 연산자를 넣어서 수식을 만든다
* 주어진 수의 순서를 바꾸면 안됨
* 식의 계산은 연산자 우선 순위 무시하고 앞에서 부터 진행 나눗셈은 정수 나눗셈으로만 몫을 취한다 음수를 양수로 나눌 때는 C++14의 기준을 따른다.
* 
* 
*/