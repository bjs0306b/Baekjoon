#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    string s; cin >> s;
    int a,b;
    int size = s.size();
    for(int i=sqrt(size);i>0;i--){
        if(size%i==0){a=i;b=size/i; break;}
    }
    char arr[b][a];
    for(int i=0;i<b;i++){
        for(int j=0;j<a;j++){
            arr[i][j] = s[a*i+j];
        }
    }
    for(int j=0;j<a;j++){
        for(int i=0;i<b;i++){
            cout << arr[i][j];
        }
    }
    
    
    return 0;
}