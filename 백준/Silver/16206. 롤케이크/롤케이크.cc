#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;

    int ans = 0;

    vector<int> end_zero, non_end_zero;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        if (num > 10)
        {
            if (num % 10)
                non_end_zero.push_back(num);
            else
                end_zero.push_back(num);
        }
        else if(num == 10) ans++;
    }
    sort(end_zero.begin(), end_zero.end());

    for (int i = 0; i < end_zero.size(); i++)
    {
        if (end_zero[i] / 10 - 1 <= m)
        {
            m -= (end_zero[i] / 10 - 1);
            ans += end_zero[i] / 10;
        }
        else
        {
            ans += m;
            cout << ans;
            return 0;
        }
    }

    for (int i = 0; i < non_end_zero.size(); i++)
    {
        if (non_end_zero[i] / 10 <= m){
            m -= (non_end_zero[i] / 10);
            ans += (non_end_zero[i] / 10);
        }
        else{
            ans += m;
            cout << ans; return 0;
        }
    }
    cout << ans;
    return 0;
}