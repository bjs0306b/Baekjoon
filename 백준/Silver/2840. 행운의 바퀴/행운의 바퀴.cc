#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<char> v;
int cnt[26];
int main(){
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> m;
    v.resize(n);

    int a; 
    char b;
    cin >> a >> b;
    
    int cur_idx = a%n;
    v[cur_idx] = b;
    for(int i=0;i<m-1;i++){
        cin >> a >> b;
        cur_idx = (cur_idx + a) % n;
        if(v[cur_idx] > 0 && v[cur_idx] != b){
            cout << '!';
            return 0;
        }
        v[cur_idx] = b;
    }

    string ans = "";
    for(int i=0;i<n;i++){
        char temp = v[(cur_idx-i+n)%n];
        if(temp){
            if(cnt[temp - 'A'] > 0){
                cout << '!';
                return 0;
            }
            cnt[temp - 'A']++;
            ans += temp;
        }
        else ans += '?';
    }
    cout << ans;

    return 0;
}