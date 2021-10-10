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
������ ���� �迭�� ���۰� ���� ���ڷ� �޴´� ���� �ش� �迭�� ���� ������ �����ϸ� �ش� ������ ������ �ٲٰ� true�� ��ȯ�Ѵ�.
������������ ���ĵ� ���� ���� �����̳ʸ� ��� ���� 
�ߺ��� �ִ� ���ҵ��� �ߺ��� �����ϰ� ������ ���礧��.
*/