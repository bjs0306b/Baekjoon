#include <bits/stdc++.h>
using namespace std;


int main(){
    cin.tie(0)->sync_with_stdio(0);
    for(int T=1;T<=10;T++){
        int n; cin >> n;
        vector<int> v(n);
        for(int i=0;i<n;i++) cin >> v[i];
        int m; cin >> m;
        for(int i=0;i<m;i++){
            char c; cin >> c;
            if(c == 'I'){
                int x,y; cin >> x >> y;
                for(int j=0;j<y;j++){
                    int s; cin >> s;
                    v.emplace(x+v.begin()+j, s);
                }
            }
            else if(c == 'D'){
                int x,y; cin >> x >> y;
                for(int i=0;i<y;i++) v.erase(x+v.begin());
            }
            else if(c == 'A'){
                int y; cin >> y;
                for(int i=0;i<y;i++){
                    int s; cin >> s;
                    v.push_back(s);
                }
            }
        }

        cout << "#" << T << " ";
        for(int i=0;i<10;i++) cout << v[i] << " ";
        cout << "\n";
    }
    

    return 0;
}