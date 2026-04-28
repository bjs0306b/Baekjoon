#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <deque>
#include <set>
#include <cmath>
using namespace std;
int arr[82];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    string a,b; cin >> a >> b;
    if(a.size() < b.size()) swap(a,b);

    auto itera = a.rbegin();
    auto iterb = b.rbegin();

    for(int i=0;i<b.size();i++){
        arr[i] = (*itera-'0') + (*iterb-'0');
        itera++;
        iterb++;
    }
    for(int i=b.size();i<a.size();i++){
        arr[i] = *itera-'0';
        itera++;
    }

    for(int i=0;i<a.size();i++){
        if(arr[i] >= 2){
            arr[i] -=2;
            arr[i+1]++;
        }
    }
    bool check = false;
    for(int i=a.size();i>=0;i--){
        if(arr[i] != 0) check = true;
        if(check) cout << arr[i];
    }
    if(!check) cout << 0;
    
    
    return 0;
}