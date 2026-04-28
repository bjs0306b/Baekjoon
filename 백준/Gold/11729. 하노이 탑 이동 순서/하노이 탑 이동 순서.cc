#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
using namespace std;

void hanoi(int n, int s, int t, int e){
    if(n){
        hanoi(n-1, s, e, t);
        cout << s << " " << e << "\n";
        hanoi(n-1, t, s, e);        
    }  
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n;
    int cnt = 0;
    for(int i=0;i<n;i++) cnt=cnt*2+1;
    cout << cnt << "\n";
    hanoi(n,1,2,3);
    
    return 0;
}