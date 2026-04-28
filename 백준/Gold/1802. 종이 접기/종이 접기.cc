#include <bits/stdc++.h>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    while(n--){
        string s; cin >> s;
        int start = 0 , jump = 2;
        bool flag = true;

        if(s.size() == 1){
            cout << "YES\n";
            continue;
        }
        for(;;){
            int temp = s[start];
            for(int i=start+jump;i<s.size();i+=jump){
                if(temp == s[i]){
                    flag = false;
                    break;
                }
                temp = s[i];
            }

            start = start * 2 + 1;
            jump *= 2;

            if(start == s.size()/2) break;
        }
        if(flag) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}