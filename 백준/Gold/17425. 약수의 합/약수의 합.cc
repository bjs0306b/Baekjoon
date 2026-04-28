#include <bits/stdc++.h>
using namespace std;

long long sum[1000001], ans[1000001];


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for(int i=1;i<1000001;i++){
        for(int j=i;j<1000001;j+=i){
            sum[j] += i;
        }
    }

    ans[1] = 1;
    for(int i=2;i<1000001;i++) ans[i] = ans[i-1] + sum[i]; 

    int n;
    cin >> n;

    while(n--){
        int num; cin >> num;
        cout << ans[num] << '\n';
    }


    return 0;
}