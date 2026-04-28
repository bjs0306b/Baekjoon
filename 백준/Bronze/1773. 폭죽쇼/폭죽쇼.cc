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

bool arr[2000001];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int a,b; cin >> a >> b;
    
    for(int i=0;i<a;i++){
        int m; cin >> m;
        for(int j=m;j<=b;j+=m) arr[j]=1;
    }
    int cnt = 0;
    for(int i=0;i<=b;i++) if(arr[i]) cnt++;
    cout << cnt;
    return 0;
}