#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    string s;
    string ans;
    int ans_length = 0;

    string temp = "";

    int cnt = 0;
    for (;;)
    {
        cin >> s;
        if (s == "E-N-D")
            break;
        for (int i = 0; i < s.size(); i++)
        {
            if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || s[i] == '-')
            {
                cnt++;
                temp += s[i];
            }
            else
            {
                if (cnt > ans_length)
                {
                    ans = temp;
                    ans_length = cnt;
                }
                temp = "";
                cnt = 0;
            }
        }
        if (cnt > ans_length)
        {
            ans = temp;
            ans_length = cnt;
        }
        temp = "";
        cnt = 0;
    }
    
    for(auto k : ans){
        char c = tolower(k);
        cout << c;
    }

    return 0;
}