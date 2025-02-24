#include <bits/stdc++.h>
using namespace std;

bool is_palindrome[50][50];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s; cin >> s;
    int size = s.size();
    bool flag = true; for(int i=0;i<size-1;i++) if(s[i] != s[i+1]){flag = false; break;}

    if(flag) cout << -1;
    else{
        for(int i=0;i<=size/2;i++){
            if(s[i] != s[size-i-1]){
                cout << size;
                return 0;
            }
        }
        cout << size-1;
    }

    return 0;
}