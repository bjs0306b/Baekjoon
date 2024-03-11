#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <deque>
#include <set>
#include <cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int arr[2][10]; for(int i=0;i<2;i++) for(int j=0;j<10;j++) cin >> arr[i][j];
    int a=0,b=0;
    for(int i=0;i<10;i++){
        if(arr[0][i] < arr[1][i]){
            b++;
        }
        else if(arr[0][i] > arr[1][i]){
            a++;
        }
    }
    if(a > b) cout << "A";
    else if(a < b) cout << "B";
    else cout << "D";
    
    return 0;
}