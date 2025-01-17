#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        int ans = 0;
        int n,m; cin >> n >> m;
        string x_str = "", y_str = "";
        for(int i=0;i<m;i++){
            char c; cin >> c;
            x_str += c;
        }
        for(int i=0;i<m;i++){
            char c; cin >> c;
            y_str += c;
        }

        int x = stoi(x_str), y = stoi(y_str);

        vector<char> v(n); for(int i=0;i<n;i++) cin >> v[i];

        for(int i=0;i<n;i++){
            string z_str = "";
            for(int j=0;j<m;j++){
                z_str += v[(i+j)%n];
            }
            int z = stoi(z_str);    
            if(x <= z && z <= y) ans++;
        }

        cout << ans << "\n";
    }

    return 0;
}