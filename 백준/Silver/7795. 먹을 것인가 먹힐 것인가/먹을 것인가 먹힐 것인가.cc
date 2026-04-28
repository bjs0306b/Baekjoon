#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    while(n--){
        int a,b; cin >> a >> b;
        int arr[a], brr[b];
        for(int i=0;i<a;i++) cin >> arr[i];
        for(int i=0;i<b;i++) cin >> brr[i];
        sort(arr,arr+a);
        sort(brr,brr+b);
        int cnt = 0;
        for(int i=0;i<a;i++){
            cnt += lower_bound(brr,brr+b,arr[i]) - brr;
        }
        cout << cnt << "\n";
    }
    
    return 0;
}