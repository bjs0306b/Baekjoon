#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    vector<int> v;
    for (auto a : s)
    {
        int num = a - '0';
        v.push_back(num / 4);
        v.push_back(num % 4 / 2);
        v.push_back(num % 2);
    }
    int i = 0;
    if (v[0] == 0)
    {
        if (v[1] == 0)
            i = 2;
        else
            i = 1;
    }

    while (i != v.size())
    {
        cout << v[i];
        i++;
    }

    return 0;
}