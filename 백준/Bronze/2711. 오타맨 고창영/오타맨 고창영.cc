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
    int n;
    cin >> n;
    while (n--)
    {
        int num;
        cin >> num;
        string str;
        cin >> str;
        for (int i = 0; i < str.size(); i++)
        {
            if (i + 1 != num)
                cout << str[i];
        }
        cout << "\n";
    }

    return 0;
}