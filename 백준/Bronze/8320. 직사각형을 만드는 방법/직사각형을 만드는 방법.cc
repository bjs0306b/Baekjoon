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
    int n,cnt=0; cin >> n;
    for(int i=1;i<=sqrt(n);i++){
        for(int j=i;j<=n;j++){
            if(i*j <= n) cnt++;
            else break;
        }
    }
    cout << cnt;
    return 0;
}