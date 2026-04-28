#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
using namespace std;
long long arr[1000001];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    arr[0] = 1;
    for (int i = 1; i < 1000001; i++)
    {
        string s;
        s = to_string(i);
        arr[i] = arr[i - 1] + count(s.begin(), s.end(), '0');
    }
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        if (a == 0)
            cout << arr[b] << "\n";
        else
            cout << arr[b] - arr[a-1] << "\n";
    }

    return 0;
}