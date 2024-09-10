#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int odd[n];
    for (int i = 0; i < n; i++)
    {
        int temp = 1;
        for (;;)
        {
            if (i - temp >= 0 && i + temp < n && arr[i - temp] == arr[i + temp])
                temp++;
            else
            {
                odd[i] = temp - 1;
                break;
            }
        }
    }
    // for(int i=0;i<n;i++) cout << odd[i] << " ";
    // cout << "\n";

    int even[n-1];
    for (int i = 0; i < n-1; i++)
    {
        int temp = 0;
        for (;;)
        {
            if (i - temp >= 0 && i + 1 + temp < n && arr[i - temp] == arr[i + 1 + temp])
                temp++;
            else
            {
                even[i] = temp;
                break;
            }
        }
    }
    // for(int i=0;i<n-1;i++) cout << even[i] << " ";
    // cout << "\n";

    int m;
    cin >> m;
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        a--; b--;
        if ((b - a) % 2)
        { // 짝
            if(even[(b+a)/2] <= (b-a)/2 ) cout << "0\n";
            else cout << "1\n";
        }
        else
        { // 홀
            if(odd[(b+a)/2] < (b-a)/2 ) cout << "0\n";
            else cout << "1\n";
        }
    }

    return 0;
}