#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<char> c(n);
    bool red = true, blue = true;
    int leftest_R=0, leftest_B=0, rightest_R = n-1 , rightest_B = n-1;
    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
        if (c[i] == 'R')
        {
            if (red)
            {
                red = false;
                leftest_R = i;
            }
            rightest_R = i;
        }
        else if (c[i] == 'B')
        {
            if (blue)
            {
                blue = false;
                leftest_B = i;
            }
            rightest_B = i;
        }
    }
    int n1 = count(c.begin(), c.begin() + rightest_B, 'R'),
        n2 = count(c.begin(), c.begin() + rightest_R, 'B'),
        n3 = count(c.begin() + leftest_B, c.end(), 'R'),
        n4 = count(c.begin() + leftest_R, c.end(), 'B');

    int ans = min(min(n1,n2), min(n3,n4));
    cout << ans;

    return 0;
}

// 가장 오른쪽 B 보다 왼쪽에 있는 R수, 가장 왼쪽 B보다 오른쪽에 있는 R의 수, 가장 오른쪽 R 보다 왼쪽에 있는 B수, 가장 왼쪽 R보다 오른쪽에 있는 B의 수,