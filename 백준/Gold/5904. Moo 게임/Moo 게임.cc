#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool dfs(int k, int len, int n) {
	if (k == 0) {
		if (n == 1) return true;
		else return false;
	}

	if (n <= (len - k - 3) / 2) return dfs(k - 1, (len - k - 3) / 2, n);
	else if (n <= (len + k + 3) / 2) {
		if (n == (len - k - 3) / 2 + 1) return true;
		else return false;
	}
	else {
		return dfs(k - 1, (len - k - 3) / 2, n - (len + k + 3) / 2);
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n;  cin >> n;
	int k = 0;
	int len = 3;
	while (len < n) {
		len = len * 2 + k + 4;
		k++;
	}

	if (dfs(k, len, n)) cout << "m";
	else cout << "o";
}