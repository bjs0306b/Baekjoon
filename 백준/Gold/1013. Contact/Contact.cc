#include <bits/stdc++.h>
using namespace std;

string s;

bool dfs(int index)
{
    if (index >= s.size()) return true;

    if (s[index] == '0'){ // 01
        if (index + 1 >= s.size()) return false;
        if (s[index + 1] == '1') return dfs(index + 2);
        return false;
    }
    else{ // 100+1+
        if (index + 3 >= s.size()) return false;

        int cnt = 0;

        index++;
        while (s[index] == '0')
        {
            if (index + 1 >= s.size())
                return false;
            index++;
            cnt++;
        }
        if (cnt < 2)
            return false;

        cnt = 0;
        while (s[index] == '1')
        {
            if (index == s.size() - 1) return true;
            index++;
            cnt++;
        }

        if (cnt > 1) return dfs(index - 1) || dfs(index);
        else return dfs(index);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    while (n--)
    {
        cin >> s;
        if (dfs(0)) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}