#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string str;
    while (getline(cin, str))
    {
        int a = 0, b = 0, c = 0, d = 0;
        for (int i = 0; i < str.size(); i++)
        {
            char cc = str[i];
            if (cc == ' ')
                d++;
            else if (cc >= 'a' && cc <= 'z')
                a++;
            else if (cc >= 'A' && cc <= 'Z')
                b++;
            else if (cc >= '0' && cc <= '9')
                c++;
        }
        cout << a << " " << b << " " << c << " " << d << "\n";
    }

    return 0;
}