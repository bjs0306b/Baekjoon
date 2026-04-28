#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<int> v;
    int sum = 0;
    for (int i = 0; i < 5; i++)
    {
        int num;
        cin >> num;
        sum += num;
        v.push_back(num);
    }
    sort(v.begin(), v.end());
    cout << sum / 5 << "\n"
         << v[2];

    return 0;
}