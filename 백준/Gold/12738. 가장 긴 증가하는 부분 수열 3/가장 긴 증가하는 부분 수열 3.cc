#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> v = {INT32_MAX};
    
    for(int i=0;i<n;i++){
        int num; cin >> num;
        
        if(v.back() < num) v.push_back(num);
        else{
            auto iter = lower_bound(v.begin(), v.end(), num);
            *iter = num;
        }
    }
    cout << v.size() << "\n";

    return 0;
}