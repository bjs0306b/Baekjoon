#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <deque>
#include <set>
#include <cmath>
using namespace std;

bool arr[1001];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int a,b,cnt=0; cin >> a >> b;
    for(int i=0;i<a;i++){int num; cin >> num; arr[num] = true;} 
    for(int i=0;i<1001;i++){
        if(arr[i]){
            for(int j=0;j<b && i+j<1001;j++)
                arr[i+j] = false;
            cnt++;
        }       
    }
    cout << cnt;

    
    
    return 0;
}