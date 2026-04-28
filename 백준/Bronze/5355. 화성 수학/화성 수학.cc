#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        float num;
        cin >> num;
        string s;
        getline(cin, s);
        for (int j = 0; j < s.size(); j++)
        {
            char c = s[j];
            if (c == '@')
                num *= 3;
            else if (c == '%')
                num += 5;
            else if (c == '#')
                num -= 7;
        }
        printf("%.2f\n", num);
    }

    return 0;
}