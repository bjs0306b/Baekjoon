#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long a, b, c;
    string str;
    cin >> a >> b;
    while (a != 0)
    {
        c = a % b;
        a /= b;
        char cc;
        if (c < 10)
            cc = '0' + c;

        else
            cc = 'A' - 10 + c;
        str.push_back(cc); 
    }
    reverse(str.begin(), str.end());
    cout << str;

    return 0;
}