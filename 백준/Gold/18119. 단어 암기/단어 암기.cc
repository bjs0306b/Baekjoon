#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n,m; cin >> n >> m;
    int active = (1 << 26) - 1; // 00000011 11111111 11111111 11111111

    vector<int> v(n);
    for(int i=0;i<n;i++){
        string s; cin >> s;
        int temp = 0;
        for(auto k : s){
            int num = k - 'a';
            temp |= (1 << num);
        }
        v[i] = temp;
    }

    for(int i=0;i<m;i++){
        int a;
        char b;
        cin >> a >> b;
        int num = b - 'a';
        if(a == 1) // 비활성화
            active = active & ~(1 << num);
        else // 활성화
            active = active | (1 << num);

        int cnt = 0;
        for(int j=0;j<n;j++){
            if((v[j] & active) == v[j]) cnt++;
        }
        cout << cnt << "\n";
    }
}