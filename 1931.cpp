/*
 한개의 회의실만 존재 이를 사용하고자 하는 N개의 회의에 대하여 회의실 시용표를 만들려고 한다.
 각 회의 i에 대해 시작시간과 끝나는 시간이 주어짐 각 회의가 겹치지 않게 하면서 회의실을 사용할 수 있느 ㄴ회의의 최대 개수를 찾아 보자
 단 회으는 한번 시작하면 중간에 중달 될 수 없으며 한 회의가 끝나는 것과 동시에 다음 회의가 시작될 수 있다.


 입력: 회의의 수 1<N<100,000
 둘째줄부터 N+1줄까지 각 회의의 정보가 주어진다. 공백을 사이에 두고 회의의 시작 시간과 끝나는 시간이 주어진다.
 pair를 사용해야 할듯

 끝나는 시간으로 정렬하자.

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