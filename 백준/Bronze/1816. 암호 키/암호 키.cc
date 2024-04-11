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
        long long a; cin >> a;
        bool check = true;
        for(int i = 2; i<= 1000000; i++){
            if(a%i==0){
                check =false;
                break;
            }
        }
        if(check) cout << "YES\n";
        else cout << "NO\n";
    }
    
    return 0;
}