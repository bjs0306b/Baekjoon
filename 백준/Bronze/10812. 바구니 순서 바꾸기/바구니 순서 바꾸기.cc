#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int a,b; cin >>a>>b;
    int arr[a+1], arr2[a+1]; for(int i=1;i<a+1;i++) {arr2[i] = i; arr[i]=i;}
    while(b--){
        int s,e,m; cin >>s>>e>>m;

        for(int i=0;i<=e-m;i++) arr2[s+i] = arr[m+i];
        for(int i=0;i<m-s;i++) arr2[e-m+s+1+i] = arr[s+i];
        
        for(int i=1;i<a+1;i++) arr[i]=arr2[i];
    }
    for(int i=1;i<a+1;i++) cout << arr[i] << " ";

    return 0;
}