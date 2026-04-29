#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv)
{
	int n; cin >> n;
    vector<int> v(n); for(int i=0;i<n;i++) cin >> v[i];
    sort(v.begin(), v.end());
    cout << v[n/2];
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}