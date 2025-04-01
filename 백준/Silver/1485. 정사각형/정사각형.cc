#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    while(n--){
        int x[4], y[4]; for(int i=0;i<4;i++) cin >> x[i] >> y[i];
        vector<int> v;
        for(int i=0;i<3;i++){
            for(int j=i+1;j<4;j++){
                int disdis = (x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j])*(y[i] - y[j]);
                v.push_back(disdis);
            }
        }
        sort(v.begin(), v.end());

        bool flag = true;
        for(int i=0;i<4;i++){
            if(v[0] != v[i]) flag = false;
        }
        for(int i=4;i<6;i++){
            if(v[0]*2 != v[i]) flag = false;
        }
        if(flag) cout << "1\n";
        else cout << "0\n";
    }

    return 0;
}   