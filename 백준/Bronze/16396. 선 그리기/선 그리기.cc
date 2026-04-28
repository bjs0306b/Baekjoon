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
bool arr[10001];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    for(int i=0;i<n;i++){
        int a,b; cin >> a>> b;
        if(a>b) swap(a,b);
        for(int j=a;j<b;j++) arr[j] = 1;
    }
    int cnt =0 ;
    for(int i=0;i<10001;i++){
        if(arr[i]) cnt++;
    }
    cout << cnt;
    return 0;
}