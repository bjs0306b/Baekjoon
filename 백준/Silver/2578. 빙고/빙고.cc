#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
using namespace std;
bool check[25];

bool check_func(){
    int cnt = 0;
    for(int i=0;i<5;i++){
        bool b = true;
        for(int j=0;j<5;j++){
            if(!check[i*5+j]) b = false;
        }
        if(b) cnt++;
    }
    for(int i=0;i<5;i++){
        bool b = true;
        for(int j=0;j<5;j++){
            if(!check[j*5+i]) b = false;
        }
        if(b) cnt++;
    }
    bool b = true;
    for(int i=0;i<5;i++){
        if(!check[6*i]) b = false;
    }
    if(b) cnt++;

    b = true;
    for(int i=0;i<5;i++){
        if(!check[4+4*i]) b = false;
    }
    if(b) cnt++;
    return cnt>2;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int arr[25]; for(int i=0;i<25;i++) cin >> arr[i];
    int call[25]; for(int i=0;i<25;i++) cin >> call[i];
    for(int i=0;i<25;i++){
        int pos = find(arr,arr+25,call[i]) - arr;
        check[pos] = true;
        if(check_func()){cout << i+1; return 0;}
    }
    
    
    return 0;
}