/*
N���� ����ġ�� N���� ������ �ִ�. ������ ������ on 1 off 0 ������ �ϳ��� ���¸� ������.
i(1<i<n)�� ����ġ�� ������ 

*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
using namespace std;

int arr1[100001];
int arr2[100001];
int result[100001];

void push(int arr[], int num) {
	for (int i = -1;i < 2;i++) {
		if (arr[num+i] == 1) {
			arr[num + i] = 0;
		}
		else {
			arr[num + i] = 1;
		}
	}

};
int main() {
	int n;
	cin >> n;

	for (int i = 0;i < n;i++) {
		scanf_s("%1d", &arr1[i]);
		arr2[i] = arr1[i];
	}
	for (int i = 0;i < n;i++) {
		scanf_s("%1d", &result[i]);
	}
	int cnt1 = 1;
	int cnt2 = 0;
	if (arr1[0] == 1) {
		arr1[0] = 0;
	}
	else {
		arr1[0] = 1;
	}
	if (arr1[1] == 1) {
		arr1[1] = 0;
	}
	else {
		arr1[1] = 1;
	}

	for (int i = 1;i < n;i++) {
		if (arr1[i - 1] != result[i-1]) {
			push(arr1, i);
			cnt1++;
		}
	}
	for (int i = 1;i < n;i++) {
		if (arr2[i - 1] != result[i-1]) {
			push(arr2, i);
			cnt2++;
		}
	}
	for (int i = 0; i < n;i++) {
		if (arr1[i] != result[i]) {
			cnt1 = -1;
		}
		if (arr2[i] != result[i]) {
			cnt2 = -1;
		}
		if (cnt1 == -1 && cnt2 == -1) {
			cout << "-1" << endl;
			return 0;
		}
	}
	if (cnt1 == -1) {
		cout << cnt2 << endl;
		return 0;
	}
	else if (cnt2 == -1) {
		cout << cnt1 << endl;
		return 0;
	}
	else if (cnt1 < cnt2) {
		cout << cnt1 << endl;
		return 0;
	}
	else{
		cout << cnt2 << endl;
		return 0;
	}
}