#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s; cin >> s;
    string ss = s + s;
    int a_cnt = count(s.begin(), s.end(), 'a');

    int b_cnt = 0;
    for(int i=0;i<a_cnt;i++) if(ss[i] == 'b') b_cnt++;

    int b_least = b_cnt;
    for(int i=a_cnt;i<ss.size();i++){
        if(ss[i] == 'b') b_cnt++;
        if(ss[i-a_cnt] == 'b') b_cnt--;

        b_least = min(b_least, b_cnt);
    }
    cout << b_least;

    return 0;
}