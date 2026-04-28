#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a, b;
    cin >> a >> b;
    map<string, int> m;
    map<int, string> m2;
    for (int i = 0; i < a; i++){
        string str; cin >> str;
        m.insert({str, i+1});
        m2.insert({i+1,str});
    }
    for (int i = 0; i < b; i++)
    {
        string s;
        cin >> s;
        if (s[0] >= '0' && s[0] <= '9')
            cout << m2[stoi(s)] << "\n";
        else
            cout << m[s] << "\n";
    }

    return 0;
}