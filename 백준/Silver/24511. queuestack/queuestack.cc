#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> v(n); for(int i=0;i<n;i++) cin >> v[i];
    vector<int> v2(n); for(int i=0;i<n;i++) cin >> v2[i];
    queue<int> q; 
    for(int i=n-1;i>=0;i--){
        if(!v[i]){
            q.push(v2[i]);
        }
    }
    int m; cin >> m;
    for(int i=0;i<m;i++){
        int num; cin >> num;
        q.push(num);
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}