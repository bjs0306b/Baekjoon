#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<int> v;
    for (int i = 0; i < 3; i++)
    {
        int n;
        cin >> n;
        v.push_back(n);
    }
    sort(v.begin(), v.end());
    cout << v[1];

    return 0;
}