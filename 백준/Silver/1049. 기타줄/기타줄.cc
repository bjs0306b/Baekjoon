#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <set>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int a,b; cin >>a>>b;
    set<int> s;
    int arr[b], arr2[b];
    for(int i=0;i<b;i++){
        cin >> arr[i] >> arr2[i];
    }
    int m = *min_element(arr, arr+b), n = *min_element(arr2,arr2+b);
    cout << min({(a+5)/6*m, a*n, a/6*m + (a%6)*n});
    
    return 0;
}