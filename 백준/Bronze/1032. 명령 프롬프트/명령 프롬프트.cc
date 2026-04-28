#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    string str[n];
    for (int i = 0; i < n; i++)
        cin >> str[i];
    int s = str[0].size();
    for (int i = 0; i < s; i++)
    {
        char c = str[0][i];
        int check = 0;
        for (int j = 1; j < n; j++)
        {
            if (str[j][i] != c)
                check = 1;
        }
        if (check == 1)
            cout << "?";
        else
            cout << c;
    }

    return 0;
}