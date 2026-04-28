#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    int cnt = 0;
    for (int i = 0; i < s.size(); i++)
        if (s[i] == ':')
            cnt++;
    string n_s = "";

    int temp;
    for (int i = 0; i < s.size() - 1; i++)
    {
        if (s[i] == ':' && s[i + 1] == ':')
        {
            temp = i + 2;
            n_s += s.substr(0, i + 2);
            break;
        }
    }

    if (cnt > 7) n_s.pop_back();

    for (int i = 0; i < 7 - cnt; i++) n_s += ':';

    n_s += s.substr(temp, s.size() - temp);

    int size = n_s.size();
    string temp1 = "";
    for (int i = 0; i < size; i++)
    {
        if (n_s[i] == ':')
        {
            for (int j = 0; j < 4 - temp1.size(); j++)
                cout << "0";
            cout << temp1 << ":";
            temp1 = "";
        }
        else
            temp1 += n_s[i];
    }
    for (int j = 0; j < 4 - temp1.size(); j++)
        cout << "0";
    cout << temp1;
    

    return 0;
}