#include <bits/stdc++.h>
using namespace std;

unordered_map<string, bool> visited;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> P(n), S(n), v(n); for(int i=0;i<n;i++) cin >> P[i];for(int i=0;i<n;i++) cin >> S[i];
    string str = ""; for(int i=0;i<n;i++) str += (v[i] + '0'); visited[str] = true;
    for(int i=0;i<n;i++) v[i] = i%3;
 
    int ans = 0;
    for(;;){
        if(P == v){
            cout << ans; break;
        }

        vector<int> temp(n); for(int i=0;i<n;i++) temp[i] = v[S[i]];
        v = temp;

        ans++;

        str = ""; for(int i=0;i<n;i++) str += (v[i] + '0');
        if(visited[str]){
            cout << -1;
            break;
        }
        visited[str] = true;

    }
    return 0;
}