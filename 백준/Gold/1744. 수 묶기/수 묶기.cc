#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> v(n);
    int ans = 0;
    for (int i = 0; i < n; i++)
        cin >> v[i];
    sort(v.begin(), v.end());
    vector<int> ne_z, po;
    for (int i = 0; i < n; i++)
    {
        if (v[i] > 0){
            if(v[i] == 1) ans++;
            else po.push_back(v[i]);
        }
            
        else
            ne_z.push_back(v[i]);
    }
    
    //cout << ans << "\n";
    if (po.size() % 2)
    {
        ans += po[0];
        for (int i = 1; i < po.size(); i += 2)
        {
            ans += po[i] * po[i + 1];
        }
    }
    else
    {
        for (int i = 0; i < po.size(); i += 2)
        {
            ans += po[i] * po[i + 1];
        }
    }
    //cout << ans << "\n";

    if (ne_z.size() % 2)
    {
        if (ne_z.size() > 1)
        {
            for (int i = 0; i < ne_z.size(); i += 2)
            {
                ans += ne_z[i] * ne_z[i + 1];
            }
        }
        ans += ne_z[ne_z.size() - 1];
    }
    else
    {
        for (int i = 0; i < ne_z.size(); i += 2)
        {
            ans += ne_z[i] * ne_z[i + 1];
        }
    }
    cout << ans;

    return 0;
}