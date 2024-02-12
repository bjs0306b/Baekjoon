#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n, arr[11], cnt = 0; memset(arr, -1, 44);
    cin >> n;
    while(n--){
        int a,b; cin >>a>>b;
        if(arr[a] == -1) arr[a] = b;
        else if(arr[a] != b){cnt++; arr[a] = b;}
    }
    cout << cnt;
    return 0;
}