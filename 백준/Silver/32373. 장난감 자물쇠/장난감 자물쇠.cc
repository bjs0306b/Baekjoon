#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k; cin >> n >> k;
    int arr[n]; for(int i=0;i<n;i++) cin >> arr[i];

    for(int i=0;i<k;i++){
        for(int j=i;j<n;j+=k){
            if(arr[j] % k != i){
                cout << "No";
                return 0;   
            }
        }
    }
    cout << "Yes";


    return 0;
}    