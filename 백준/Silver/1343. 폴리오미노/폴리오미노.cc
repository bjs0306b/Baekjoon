#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;  
    vector<string> v;
    string ss = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'X')
            ss += 'X';
        else if (s[i] == '.')
        {
            int cnt = count(ss.begin(), ss.end(), 'X');
            ss = "";
            if (cnt % 2)
            {
                cout << -1;
                return 0;
            }
            else
            {
                if (cnt % 4)
                {
                    for (int j = 0; j < cnt / 4; j++)
                        v.push_back("AAAA");
                    v.push_back("BB");
                }
                else
                    for (int j = 0; j < cnt / 4; j++)
                        v.push_back("AAAA");
            }
            v.push_back(".");
        }
    }
    int cnt = count(ss.begin(), ss.end(), 'X');
    if (cnt % 2)
    {
        cout << -1;
        return 0;
    }
    else
    {
        if (cnt % 4)
        {
            for (int j = 0; j < cnt / 4; j++)
                v.push_back("AAAA");
            v.push_back("BB");
        }
        else
            for (int j = 0; j < cnt / 4; j++)
                v.push_back("AAAA");
    }
    for(auto a : v) cout << a;

    return 0;
}