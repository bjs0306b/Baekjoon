#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int a[31];
    for(int i=1;i<31;i++) a[i] = 1;
    for(int i=0;i<28;i++){
        int num; cin>>num;
        a[num] = 0;
    }
    for(int i=1;i<31;i++){
        if(a[i] == 1) cout << i << "\n";
    }
    return 0;
}