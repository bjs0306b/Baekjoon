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
    for (int i = n; i > 0; i--)
    {
        string str = to_string(i);
        bool check = true;
        for (int j = 0; j < str.length(); j++)
        {
            if (!(str[j] == '4' || str[j] == '7')) check = false;
        }
        if(check){ cout << i; break;}
    }
    return 0;
}