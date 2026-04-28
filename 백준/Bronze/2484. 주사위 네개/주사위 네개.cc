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
    int ans = 0;
    for(int i=0;i<n;i++){
        int a,b,c,d; cin >> a >> b >> c >> d;
        int arr[6]; memset(arr, 0, sizeof(arr));
        arr[--a]++; arr[--b]++; arr[--c]++; arr[--d]++;

        int mx = *max_element(arr, arr+6);
        int mx_pos = max_element(arr, arr+6) - arr + 1;

        if(mx == 4) ans = max(ans,  50000 + 5000 * mx_pos);
        else if(mx == 3) ans = max(ans, 10000 + 1000 * mx_pos);
        else if(mx == 2){
            int cnt = 0;
            for(int i=0;i<6;i++){
                if(arr[i] == 2) cnt++;
            }
            if(cnt == 2) ans = max(ans ,2000 + 250 * (a+b+c+d+4));
            else ans = max(ans,  1000 + 100 * mx_pos);
        }
        else if(mx == 1) ans = max(ans,  100 * (max({a,b,c,d})+1));
    }
    cout << ans;
    return 0;
}