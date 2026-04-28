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
    int n; cin >> n;
    int arr[n]; for(int i=0; i<n; i++) cin >> arr[i];
    int mn = *min_element(arr, arr+n);
    cout << "1\n";
    for(int i=2;i<=mn;i++){
        bool check = true;
        for(int j=0; j<n; j++){
            if(arr[j]%i != 0){check = false; break;}
        }
        if(check) cout << i << "\n";
    }
    
    return 0;
}

