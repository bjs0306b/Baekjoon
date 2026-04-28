#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <set>
#include <cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    while(n--){
        string a,b; cin >> a >> b;
        cout << "Distances: ";
        for(int i=0;i<a.size();i++){
            if(a[i] <= b[i]) cout << b[i]-a[i] << " ";
            else cout << 26-(a[i]-b[i]) << " ";
        }
        cout << "\n";
    }
    
    return 0;
}