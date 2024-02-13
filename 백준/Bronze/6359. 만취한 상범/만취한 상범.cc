#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int num; cin >> num;
        int ans = 1;
        while(ans*ans <= num) ans++;
        cout << ans-1 << "\n";
    }
    
    return 0;
}