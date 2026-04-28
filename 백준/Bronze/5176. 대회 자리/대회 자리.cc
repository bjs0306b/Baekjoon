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
    while (n--)
    {
        int a,b; cin >> a >> b;
        int ans = 0;
        bool arr[a+1]; memset(arr, 0, sizeof(arr));
        for(int i=0;i<a;i++){
            int num; cin >> num;
            if(arr[num]){
                ans++;     
            }
            else arr[num] = 1;
        }
        cout << ans << "\n";
    }  
    return 0;
}