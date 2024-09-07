#include <bits/stdc++.h>
using namespace std;

bool arr[4000001]; // false - 소수 , true - 소수x

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;

    arr[1] = true;
    vector<long long> sosu;

    for (int i = 2; i < 4000001; i++)
    {   
        if(!arr[i]){
            sosu.push_back(i);
            int temp = i;
            while(temp + i < 4000001){
                temp += i;
                arr[temp] = true;
            }
        }
    }

    int ans = 0;
    int start = 0, end = 0, sum = 0;

    while (end <= sosu.size()) {
        if (sum < n) {
            if (end == sosu.size()) break;
            sum += sosu[end++];
        } else if (sum == n) {
            ans++;
            sum -= sosu[start++];
        } else {
            sum -= sosu[start++];
        }
    }
    cout << ans;
    
    
    

    return 0;
}