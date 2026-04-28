#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        if(i==0){
            for(int j=0;j<n-i-1;j++) cout << " ";
            cout << "*\n";
        }
        else if(i==n-1){
            for(int j=0;j<2*n-1;j++) cout<<"*";
        }
        else{
            for(int j=0;j<n-i-1;j++) cout << " ";
            cout << "*";
            for(int j=0;j<2*i-1;j++) cout << " ";
            cout << "*\n";
        }
    }
    
    return 0;
}