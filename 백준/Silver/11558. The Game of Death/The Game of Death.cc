#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> v;
bool visited[10001];

void input() {
	cin >> n;
	v.resize(n + 1); for (int i = 1; i <= n; i++) {
		cin >> v[i]; visited[i] = false;
	}
}

void dfs(int num, int dep) {
	if (num == n) {
		cout << dep << "\n";
		return;
	}
	if (visited[num]) {
		cout << "0\n";
		return;
	}
    visited[num] = true;
	dfs(v[num], dep + 1);
}

void solve() {
	dfs(1,0);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		input();
		solve();
	}

	return 0;
}