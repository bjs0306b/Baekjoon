#include <bits/stdc++.h>
using namespace std;
int ans;
vector<int> v;
int n;
void func(int a, int b, int c)
{
    int mul1 = 1, mul2 = 1, mul3 = 1, mul4 = 1;
    for (int i = 0; i < a; i++)
        mul1 *= v[i];
    for (int i = a; i < b; i++)
        mul2 *= v[i];
    for (int i = b; i < c; i++)
        mul3 *= v[i];
    for (int i = c; i < n; i++)
        mul4 *= v[i];
    
    ans = max(ans, mul1 + mul2 + mul3 + mul4);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        v.push_back(num);
    }

    for (int i = 1; i < n - 2 && i < 4; i++)
    {
        for (int j = i + 1; j < n - 1 && j < i + 5; j++)
        {
            for (int k = j + 1; k < n && k < j + 5; k++)
            {
                func(i, j, k);
            }
        }
    }
    cout << ans;

    return 0;
}