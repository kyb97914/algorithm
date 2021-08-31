#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int answer = 0;
	for (int i = 1;i <= n;i++) {
		//2번째 와 3번째의 차이와 1번째와 2번째의 차이가 같으면 됨
		//1번째는 숫자 %10 2번째는 (숫자/10)%10 3번째는 숫자 /100
		if (i < 100) {
			answer++;
		}
		else if (((i / 10) % 10) - (i % 10) == (i / 100) - ((i / 10) % 10)) {
			answer++;
		}
	}
	cout << answer << endl;
}