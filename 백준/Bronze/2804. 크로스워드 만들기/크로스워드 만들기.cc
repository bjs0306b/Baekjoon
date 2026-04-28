#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    string a,b; cin >> a>>b;
    int m,n;
    for(int i=0;i<a.size();i++){
        char c = a[i];
        int pos;
        if(find(b.begin(), b.end(), c) != b.end()){
            pos = find(b.begin(), b.end(), c) - b.begin();
            m = i; n = pos; break;
        }
    }
    for(int i=0;i<b.size();i++){
        for(int j=0;j<a.size();j++){
            if(j == m){
                cout << b[i];
            }
            else if(i == n){
                cout << a[j];
            }
            else cout << ".";
        }
        cout << "\n";
    }
    
    return 0;
}