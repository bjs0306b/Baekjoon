#include <bits/stdc++.h>
using namespace std;

int n,k;
bool arr[50][21];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> k;
    if(k < 5){
        cout << 0; return 0;
    }
    for(int i=0;i<n;i++){
        string s; cin >> s;
        for(auto kk : s){
            int num = kk - 'a';
            if(num == 1) arr[i][0] = true;
            else if(num == 3) arr[i][1] = true;
            else if(num > 3 && num < 8) arr[i][num-2] = true;
            else if(num > 8 && num < 13) arr[i][num-3] = true;
            else if(num > 13 && num < 19) arr[i][num-4] = true;
            else if(num > 19) arr[i][num-5] = true;
        }
    }

    vector<int> v(21, 1);
    for(int i=0;i<26-k;i++) v[i] = 0;

    int ans = 0;
    do{
        int cnt = 0;
        for(int i=0;i<n;i++){ 
            bool flag = true;
            for(int j=0;j<21;j++){
                if(arr[i][j] == true && v[j] == false ){
                    flag = false;
                    break;
                }
            }
            if(flag) cnt++;
        }
        ans = max(ans, cnt);
    }while(next_permutation(v.begin(), v.end()));

    cout << ans;

    return 0;
}