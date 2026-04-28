#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a, b;
    cin >> a >> b;
    set<int> s;
    for (int i = 2; i <= a; i++)
        s.insert(i);
    int p;
    for (;;)
    {
        p = *s.begin();
        for (int i = p; i <= a; i += p)
        {
            if (s.find(i) != s.end())
            {
                s.erase(i);
                b--;
            }
            if (b == 0)
            {
                cout << i;
                return 0;
            }
        }
    }

    return 0;
}