#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <deque>
#include <set>
#include <cmath>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    for (;;)
    {
        cin >> n;
        if (n == 0)
            return 0;
        string min_string = "{";
        string ans;
        while (n--)
        {
            string s, temp = "";
            cin >> s;
            for (int i = 0; i < s.size(); i++)
                temp.push_back(tolower(s[i]));
            if (temp < min_string)
            {
                min_string = temp;
                ans = s;
            }
        }
        cout << ans << "\n";
    }

    return 0;
}