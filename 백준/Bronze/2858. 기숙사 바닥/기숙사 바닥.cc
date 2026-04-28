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
    int a,b; cin >> a >> b;
    int sum = (a-4)/2;
    for(int i=1;i<=sum/2;i++){
        if(i*(sum-i) == b){
           int ans = i+2;
           int ans2 = sum-i+2;

           cout << max(ans, ans2) << " " << min(ans, ans2);
        }
    }
    
    
    return 0;
}