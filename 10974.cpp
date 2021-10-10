#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = i + 1;
    }
    do {
        for (int i = 0; i < n; i++) {
            cout << a[i] << ' ';
        }
        cout << '\n';
    } while (next_permutation(a.begin(), a.end()));
    return 0;
}

/*

bool nextpermutation(first,last)
순열을 구할 배열의 시작과 끝을 인자로 받는다 만약 해당 배열에 다음 순열이 존재하면 해당 순열의 순서를 바꾸고 true를 반환한다.
오름차순으로 정렬된 값을 가진 컨테이너만 사용 가능 
중복이 있는 원소들은 중복을 제외하고 순열을 만든ㄷ다.
*/