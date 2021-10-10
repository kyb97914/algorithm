#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> arr[1001];
bool check[1001];
void dfs(int start) {
	check[start] = true;
	cout << start;
	for (int i = 0;i < arr[start].size();i++) {
		if (check[arr[start][i]] == false) {
			dfs(arr[start][i]);
		}
	}
}

void bfs(int start) {
	queue<int> q;
	memset(check, false, sizeof(check));
	check[start] = true;
	q.push(start);
	while (!q.empty()) {
		int a = q.front();
		q.pop();
		cout << a;
		for (int i = 0;i < arr[a].size();i++) {
			if(check[arr[a][i]]==false){
				check[arr[a][i]] = true;
				q.push(arr[a][i]);
			}
		}

	}
}

int main() {
	int n, m, start;
	cin >> n >> m >> start;
	for(int i=0;i<m;i++){
		int a, b;
		cin >> a >> b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	for (int i = 1;i <= n;i++) {
		sort(arr[i].begin(), arr[i].end());
	}
	dfs(start);
	puts("");
	bfs(start);
	puts("");
	return 0;
}