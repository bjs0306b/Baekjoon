#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector<int> v(n); for(int i=0;i<n;i++) cin >> v[i];

    for(int i=0;i<n;i++){
        int num = v[i] + 1; // num이 소수여야 함.
        bool flag = true;
        for(int j=2;j<=sqrt(num);j++){
            if(num % j == 0){
                flag = false;
                break;
            }
        }
        if(flag){
            cout << "1\n" << "1 " << num << "\n"; 
        }
        else cout << "0\n";
    }
    
    return 0;
}