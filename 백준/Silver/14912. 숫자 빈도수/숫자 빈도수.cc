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
    int m; char n; cin >> m >> n;
    int ans = 0;
    for(int i=1;i<=m;i++){
        string temp = to_string(i);
        ans += count(temp.begin(), temp.end(), n);
    }
    cout << ans;
    
    return 0;
}