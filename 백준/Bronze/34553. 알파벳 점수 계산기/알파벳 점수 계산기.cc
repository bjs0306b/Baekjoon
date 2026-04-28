#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s; cin >> s;
    int ans = 1;
    int word_score = 1;
    for(int i=1;i<s.size();i++){
        if(s[i] > s[i-1]) word_score++;
        else word_score = 1;
        ans += word_score;
    }
    cout << ans;
    
    return 0;
}