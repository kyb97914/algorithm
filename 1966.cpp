#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int num;
	cin >> num;
	vector<int> answer;
	for (int i = 0;i < num;i++) {
		int n;
		cin >> n;
		int m;
		cin >> m;
		vector<int> arr(n);
		for (int j = 0;j < n;j++) {
			cin >> arr[j];
		}//���� ����
		int count = 0;
		while (1) {
			if (max_element(arr.begin(), arr.end()) - arr.begin() == 0) {
				//�տ� ���� ���� ū�̶��
				count++;
				if (m == 0) {
					answer.push_back(count);
					break;
				}
				else {
					arr.erase(arr.begin());
					//����
				}
			}
			else {
				arr.push_back(arr[0]);
				arr.erase(arr.begin());
			}
			if (m == 0) {
				m = arr.size()-1;
			}
			else {
				m--;
			}
		}
	}
	for (int i = 0;i < num;i++) {
		cout << answer[i] << endl;
	}
}
/*
for (int i = 0;i < num;i++) {
		cout<<answer[i]<<endl;
	}
*/