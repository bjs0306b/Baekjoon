#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string str;
    cin >> str;
    int s = str.size();
    int b = 0;
    for (int i = 0; i < s / 2; i++)
    {
        if (str[i] != str[s - 1 - i])
            b = 1;
    }
    if (b == 1)
        cout << 0;
    else
        cout << 1;

    return 0;
}