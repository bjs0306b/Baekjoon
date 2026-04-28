#include <iostream>
using namespace std;

int N, A, B, C;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> A >> B >> C;
	cout << min(A, N) + min(B, N) + min(C, N);
}