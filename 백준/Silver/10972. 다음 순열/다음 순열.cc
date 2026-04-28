#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <set>
#include <cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n, cnt=0; cin >> n; int arr[n];
    for(int i=0;i<n;i++) cin >> arr[i];
    for(int i=n-1;i>0;i--){
        if(arr[i-1] < arr[i]){
            cnt++;
            set<int> s;
            for(int j = i; j<n;j++){
                s.insert(arr[j]);
            }
            int temp;
            for(auto k : s) if(k>arr[i-1]){temp = k; break;}
            s.erase(temp);
            s.insert(arr[i-1]);
            arr[i-1] = temp;

            for(int j=0;j<i;j++) cout << arr[j] << " ";
            for(auto k : s) cout << k << " ";
            break;
        }
    }
    if(cnt==0) cout << -1;

    return 0;
}