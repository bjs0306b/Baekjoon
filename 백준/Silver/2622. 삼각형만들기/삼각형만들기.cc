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
    int  c = (n-1)/2;
    int cnt = 0;
    for(int i = c; i > 0; i--){
        for(int a = 1; a <= (n-i)/2; a++){
            if(a > i) break;
            if(n-i-a > i) continue;;
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}