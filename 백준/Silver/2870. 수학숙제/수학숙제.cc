#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;

bool aaa(string a, string b)
{
    if (a.size() == b.size())
        return a < b;
    return a.size() < b.size();
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<string> ms;

    while (n--)
    {
        string s;
        cin >> s;
        string temp = "";
        for (auto k : s)
        {
            if (k >= '0' && k <= '9')
                temp += k;
            else
            {
                if (temp.size())
                {
                    string temptemp = "";
                    bool check = false;
                    for (auto kk : temp)
                    {
                        if (kk != '0')
                            check = true;
                        if (check)
                            temptemp += kk;
                    }

                    if (temptemp == "")
                        temptemp = "0";
                    ms.push_back(temptemp);
                }
                temp = "";
            }
        }
        if (temp.size())
        {
            string temptemp = "";
            bool check = false;
            for (auto kk : temp)
            {
                if (kk != '0')
                    check = true;
                if (check)
                    temptemp += kk;
            }

            if (temptemp == "")
                temptemp = "0";
            ms.push_back(temptemp);
        }
    }
    sort(ms.begin(), ms.end(), aaa);
    for (auto k : ms)
        cout << k << '\n';

    return 0;
}