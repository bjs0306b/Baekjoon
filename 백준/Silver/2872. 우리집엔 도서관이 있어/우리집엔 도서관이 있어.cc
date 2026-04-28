#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> v(n); for(int i=0;i<n;i++) cin >> v[i];

    int temp = n;
    for(auto iter = v.rbegin(); iter != v.rend(); iter++){
        if(temp == *iter) temp--;
    }
    
    cout << temp;

    return 0;
}