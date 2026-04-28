#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <set>
#include <cmath>
using namespace std;

int func(int a, int b){
    while(b){
        int temp = a%b;
        a = b;
        b = temp;
    }
    return a;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    while(n--){
        int a,b; cin >> a >> b;
        int ans1 = func(a,b);
        int ans2 = a*b/ans1;
        cout << ans2 << " " << ans1 << "\n";
    }
    
    return 0;
}