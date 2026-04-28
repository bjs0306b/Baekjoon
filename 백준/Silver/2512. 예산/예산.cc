#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <deque>
#include <set>
#include <cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n,sum=0,mx=0; cin >> n;
    int arr[n]; for(int i=0;i<n;i++){cin >> arr[i]; sum+=arr[i]; mx = max(mx, arr[i]);}
    int m; cin >> m;
    if(sum < m) cout << mx;
    else{
        for(int i=mx;i>0;i--){
            int summ=0;
            for(int j=0;j<n;j++){
                if(arr[j] > i) summ += i;
                else summ += arr[j];
            }
            if(summ <= m){cout << i; return 0;}
        }
    }
    
    return 0;
}