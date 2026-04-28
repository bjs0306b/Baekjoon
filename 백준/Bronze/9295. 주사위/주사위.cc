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
    int n; cin >> n;
    for(int i=1;i<=n;i++){
        cout << "Case " << i << ": ";
        int a,b; cin >> a >> b; cout << a+b << "\n";
    }
    
    return 0;
}