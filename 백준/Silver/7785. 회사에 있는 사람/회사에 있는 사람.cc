#include <iostream>
#include <algorithm>
#include <set>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    set<string, greater<>> s;
    while (n--)
    {
        string a, b;
        cin >> a >> b;
        if (b == "enter")
            s.insert(a);
        else if (b == "leave")
            s.erase(a);
    }
    for (auto a : s)
        cout << a << "\n";
    return 0;
}