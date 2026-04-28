#include <bits/stdc++.h>
using namespace std;

set<string> kind_of_cheese;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;

        int size = s.size();   
        if(s.size() < 6)continue;
        if (s.substr(size - 6, 6) == "Cheese")
        {
            kind_of_cheese.insert(s.substr(0, size - 6));
        }
    }
    if(kind_of_cheese.size() > 3) cout << "yummy";
    else cout << "sad";

    return 0;
}