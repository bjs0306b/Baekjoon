#include <bits/stdc++.h>
using namespace std;

int ans;

int main(){
    cin.tie(0)->sync_with_stdio(0); 
    
    string s; cin >> s;
    int size = s.size();

    queue<int> q;
    for(int i=0;i<size;i++){
        if(s[i] == 'B')
            q.push(i);
        else if(s[i] == 'C'){
            if(q.size()){
                s[q.front()] = '.';
                q.pop();
                ans++;
            }
        }
    }

    int cnt_a = 0;
    for(int i=0;i<size;i++){
        if(s[i] == 'A') cnt_a++;
        else if(s[i] == 'B'){
            if(cnt_a){
                cnt_a--;
                ans++;
            }
        }
    }
    
    cout << ans;

    return 0;
}