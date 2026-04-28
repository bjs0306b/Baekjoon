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
    int mx = 0;
    for(int i=1;i<=b;i++){
        string temp = to_string(a*i);
        reverse(temp.begin(),temp.end());
        mx = max(mx,stoi(temp));
    }
    cout << mx;
    
    
    return 0;
}