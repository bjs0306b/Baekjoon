#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    vector<int> d(n);
    for (int i = 0; i < n; i++)
        cin >> d[i];
    sort(d.begin(), d.end(), greater<int>());
    int sum_calories = c, sum_price = a;

    for (int i = 0; i < n; i++)
    {
        if (sum_calories / sum_price <= (sum_calories + d[i]) / (sum_price + b))
        {
            sum_calories += d[i];
            sum_price += b;
        }
        else
            break;
    }
    cout << sum_calories / sum_price;

    return 0;
}