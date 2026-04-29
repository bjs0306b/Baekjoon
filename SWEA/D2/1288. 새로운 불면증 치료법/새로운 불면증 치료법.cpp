#include <bits/stdc++.h>
using namespace std;

int n;
void input(){
    cin >> n;
}

int solve(){
    int cnt = 0;
    vector<bool> visited(10, false);
    for(int i=1;;i++){
        int num = n * i;
        while(num){
            int k = num % 10;
            if(!visited[k]){
                visited[k] = true;
                cnt++;
            }
            num /= 10;
        }
        if(cnt == 10) return n*i;
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    for(int i=1;i<=t;i++){
        input();
        cout << "#" << i << " " << solve() << '\n';
    }

    return 0;
}