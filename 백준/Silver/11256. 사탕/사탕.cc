#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    long long n; cin >> n;
    vector<int> v;
    while(n--){
        long long a,b; cin >> a >> b;
        multiset<int, greater<int>> s;

        for(int i=0;i<b;i++){
            int c,d; cin >> c >> d;
            s.insert(c*d);
        }
        int cnt = 0;
        for(auto k : s){
            a -= k;
            cnt++;
            if(a <= 0){
                cout << cnt << endl;
                break;
            }
        }
    }
  

    return 0;
}