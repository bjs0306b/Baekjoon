#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int num; cin >> num;
        int mx=0; string mx_name;
        while(num--){
            int m; string name; cin >> m >> name;
            if(mx < m){mx = m; mx_name = name;}
        }
        cout << mx_name << "\n";
    }
    
    return 0;
}