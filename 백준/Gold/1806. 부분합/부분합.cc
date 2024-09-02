#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int ans;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        int num; cin >> num;
        if (i)
            arr[i] = arr[i - 1] + num;
        else
            arr[i] = num;
    }
    if (arr[n - 1] < m)
    {
        cout << 0;
        return 0;
    }
    for (int i = 0; i < n; i++){
        if (arr[i] >= m){
            ans = i + 1;
            break;
        }
    }
    for(;;){
        int a = 0;
        for(;;){
            if (arr[a+ans-1] - arr[a] >= m){ans--; break;}
            else{
                if(a == n - ans){cout << ans; return 0;}
                a++;
            }
        }
    }
}