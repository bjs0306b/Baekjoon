#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, sum = 0;
    cin >> n;
    vector<int> v(n); for(int i=0;i<n;i++){cin >> v[i]; sum += v[i];}
    if(sum%2){
        cout << 1;
    }
    else{
        int temp = 0;
        int cnt = 0;
        for(int i=0;i<n;i++){
            temp += v[i];
            if(temp % 2 == 0){
                cnt++;
                temp = 0;
            }
        }
        if(cnt > 1) cout << 1;
        else cout << 0;
    }


    return 0;
}