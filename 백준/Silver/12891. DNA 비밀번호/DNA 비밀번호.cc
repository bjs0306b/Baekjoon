#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    int A[4], cnt[4]; 
    for (int i = 0; i < 4; i++){
        cin >> A[i];
        cnt[i] = 0;
    }
        
    int ans = 0;

    
    for (int i = 0; i < m; i++)
    {
        switch (s[i])
        {
            case 'A':
            {
                cnt[0]++;
                break;
            }
            case 'C':
            {
                cnt[1]++;
                break;
            }
            case 'G':
            {
                cnt[2]++;
                break;
            }
            case 'T':
            {
                cnt[3]++;
                break;
            }
        }
    }
    
    bool flag = true;
    for (int j = 0; j < 4; j++)
    {
        if (A[j] > cnt[j])
        {
            flag = false;
            break;
        }
    }
    if (flag)
        ans++;

    for (int i = 0; i < n - m; i++)
    {
        switch (s[i])
        {
            case 'A':
            {
                cnt[0]--;
                break;
            }
            case 'C':
            {
                cnt[1]--;
                break;
            }
            case 'G':
            {
                cnt[2]--;
                break;
            }
            case 'T':
            {
                cnt[3]--;
                break;
            }
        }
        switch (s[i + m])
        {
            case 'A':
            {
                cnt[0]++;
                break;
            }
            case 'C':
            {
                cnt[1]++;
                break;
            }
            case 'G':
            {
                cnt[2]++;
                break;
            }
            case 'T':
            {
                cnt[3]++;
                break;
            }
        }

        bool flag = true;
        for (int j = 0; j < 4; j++)
        {
            if (A[j] > cnt[j])
            {
                flag = false;
                break;
            }
        }
        if (flag)
            ans++;
    }
    cout << ans;
}