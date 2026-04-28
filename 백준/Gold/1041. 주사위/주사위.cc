#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n;
    cin >> n;
    vector<long long> v(6); for(int i=0;i<6;i++) cin >> v[i];
    long long two = INT32_MAX, three;
    for(int i=0;i<6;i++){
        for(int j=0;j<6;j++){
            if(i != j && i+j != 5){
                two = min(two, v[i]+v[j]);
            }
        }
    }
    vector<int> three_v = {v[0]+v[1]+v[2], v[0]+v[4]+v[2], v[0]+v[4]+v[3], v[0]+v[3]+v[1], 
        v[5]+v[1]+v[2], v[5]+v[4]+v[2], v[5]+v[4]+v[3], v[5]+v[3]+v[1]};
    three = *min_element(three_v.begin(), three_v.end());
    
    sort(v.begin(), v.end());
    
    long long one = v[0];
    

    if(n == 1) cout << v[0]+v[1]+v[2]+v[3]+v[4];
    else cout << (5*n*n-16*n+12)*one + (8*n-12)*two + 4 * three;

    return 0;
}