#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <cmath>
#include <set>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> v, v2, v3;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        v2.push_back(num);
        v.push_back(num);
    }
    sort(v2.begin(), v2.end());
    for (auto k : v)
    {
        int pos = find(v2.begin(), v2.end(), k) - v2.begin();
        while(find(v3.begin(), v3.end(), pos) != v3.end())
            pos++;
        v3.push_back(pos);
    }
    for(auto k : v3) cout << k << " ";
    return 0;
}