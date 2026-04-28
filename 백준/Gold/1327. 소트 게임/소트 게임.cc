#include <bits/stdc++.h>
using namespace std;

unordered_map<string, bool> um;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    string s = ""; for(int i=0;i<n;i++){char c; cin >> c; s += c;}
    string ans = "";
    for(int i=1;i<=n;i++) ans += ('0' + i);
    
    queue<string> q; q.push(s); um[s] = true;

    int cnt = 0;
    while(!q.empty()){
        int size = q.size();
        for(int i=0;i<size;i++){
            string front = q.front(); q.pop();
            if(front == ans){cout << cnt; return 0;}
            for(int j=0;j<n-k+1;j++){
                string temp = front;
                reverse(temp.begin()+j, temp.begin()+j+k);
                if(!um[temp]){q.push(temp); um[temp] = true;}
            }
        }
        cnt++;      
    }
    cout << -1;


    return 0;
}