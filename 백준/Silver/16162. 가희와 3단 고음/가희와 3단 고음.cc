#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, a, d;
    cin >> n >> a >> d;

    int cnt = 0;
    while(n--){
        int num; cin >> num;
        if(num == a){
            cnt++;
            a += d;
        }
    }
    cout << cnt;

    return 0;
}