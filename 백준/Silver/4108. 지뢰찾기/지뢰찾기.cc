#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

char A[100][100];

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
    
	int n, m;
	int dx[] = { -1,-1,-1,0,0,1,1,1 }, dy[] = { -1,0,1,-1,1,-1,0,1 };
	for (;;) {
		cin >> n >> m;
		if (n == 0 && m == 0) break;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> A[i][j];
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (A[i][j] == '*') cout << '*';
				else {
					int cnt = 0;
					for (int k = 0; k < 8; k++) {
						int nx = i + dx[k], ny = j + dy[k];
						if (nx >= 0 && nx < n && ny >= 0 && ny < m && A[nx][ny] == '*') {
							cnt++;
						}
					}
					cout << cnt;
				}
			}
			cout << "\n";
		}

	}
}
