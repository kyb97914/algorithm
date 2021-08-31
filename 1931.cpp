/*
 �Ѱ��� ȸ�ǽǸ� ���� �̸� ����ϰ��� �ϴ� N���� ȸ�ǿ� ���Ͽ� ȸ�ǽ� �ÿ�ǥ�� ������� �Ѵ�.
 �� ȸ�� i�� ���� ���۽ð��� ������ �ð��� �־��� �� ȸ�ǰ� ��ġ�� �ʰ� �ϸ鼭 ȸ�ǽ��� ����� �� �ִ� ��ȸ���� �ִ� ������ ã�� ����
 �� ȸ���� �ѹ� �����ϸ� �߰��� �ߴ� �� �� ������ �� ȸ�ǰ� ������ �Ͱ� ���ÿ� ���� ȸ�ǰ� ���۵� �� �ִ�.


 �Է�: ȸ���� �� 1<N<100,000
 ��°�ٺ��� N+1�ٱ��� �� ȸ���� ������ �־�����. ������ ���̿� �ΰ� ȸ���� ���� �ð��� ������ �ð��� �־�����.
 pair�� ����ؾ� �ҵ�

 ������ �ð����� ��������.

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct timer {
	int start;
	int end;
};

bool compare(timer &t1, timer &t2){
	if (t1.end == t2.end) {
		return t1.start < t2.start;
	}
	return t1.end < t2.end;
}
int main() {
	int n;
	cin >> n;
	vector<timer> arr(n);
	for (int i = 0;i < n;i++) {
		cin >> arr[i].start >> arr[i].end;
	}

	sort(arr.begin(), arr.end(), compare);

	int cnt=0;
	int finish = 0;
	for (int i = 0;i < n;i++) {
		if (arr[i].start > finish) {
			finish = arr[i].end;
			cnt++;

		}
	}

	cout << cnt << endl;
	return 0;
}