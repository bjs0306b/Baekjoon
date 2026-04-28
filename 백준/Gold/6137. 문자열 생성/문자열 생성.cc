#include <bits/stdc++.h>
using namespace std;

int n;
vector<char> v;
void input(){
    cin >> n;
    v.resize(n);
    for(int i=0;i<n;i++) cin >> v[i];
}

void solve(){
    int p1 = 0, p2 = n-1;
    for(int i=0;i<n;i++){
        if(i > 0 && i % 80 == 0) cout << "\n";
        
        if(v[p1] > v[p2]) cout << v[p2--];
        else if(v[p1] < v[p2]) cout << v[p1++];
        else{
            int temp = 1;
            bool flag = false;
            while(p1 + temp <= p2 - temp){
                if(v[p1+temp] < v[p2-temp]){
                    cout << v[p1++];
                    flag = true;
                    break;
                }
                else if(v[p1+temp] > v[p2-temp]){
                    cout << v[p2--];
                    flag = true;
                    break;
                }
                temp++;
            }
            if(flag) continue;
            cout << v[p1++];
        }
    } 
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    input();
    solve();

    return 0;
}