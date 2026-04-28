#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <set>
using namespace std;
long long sum;
int arr[31];
vector<int> v;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        sum = 1;
        v.clear();
        multiset<string> ms;
        set<string> s;

        int num;
        cin >> num;
        while (num--)
        {
            string a, b;
            cin >> a >> b;
            ms.insert(b);
            s.insert(b);
        }
        for (auto at : s)
        {
            sum *= (ms.count(at)+1);
        }
        
        cout << sum-1 << "\n";
    }

    return 0;
}