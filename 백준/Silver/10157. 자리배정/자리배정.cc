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
    int a,b,c; cin >> a >> b >> c;
    if(a*b < c){cout << 0; return 0;}
    int arr[a][b]; memset(arr, 0, 4*a*b);
    int temp = 0;
    int i=0,j=0;
    bool check = false;
    for(;;){
        while(j < b-1 && !arr[i][j+1]){arr[i][j]= ++temp; if(temp==c){check = true; break;} j++;} if(check) break;
        while(i < a-1 && !arr[i+1][j]){arr[i][j]= ++temp; if(temp==c){check = true; break;} i++;}if(check) break;
        while(j > 0 && !arr[i][j-1]){arr[i][j]= ++temp; if(temp==c){check = true; break;} j--;}if(check) break;
        while(i > 0 && !arr[i-1][j]){arr[i][j]= ++temp; if(temp==c){check = true; break;} i--;}if(check) break;
        if(temp == a*b-1) break;
    }
    cout << i+1 << " " << j+1;
    
    return 0;
}