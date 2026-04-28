#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;

// bool func(int n, int k){
//     if(n < 3){
//         if(n == 1) return false;
//         else return true;
//     }
//     else{
//         if(n / (int)pow(3,k-1) == 1 ) return false;
//         else{
//             int temp = pow(3,k-1);
//             return func(n%temp, k-1);
//         }
//     }
// }

// int main(){
//     ios_base::sync_with_stdio(0);cin.tie(0);
    
//     int n; 
//     while(cin >> n){
//         for(int i=0;i<pow(3,n);i++){
//             if(func(i,n)) cout << "-";
//             else cout << " ";
//         }
//         cout << "\n";
//     }
//     return 0;
// }

void func(int n){
    int num = pow(3,n);

    if(n==0){
        cout << "-";
        return;
    }
    func(n-1);

    for(int i=0;i<num/3;i++) cout << " ";

    func(n-1);
}
int main(){
    int n;
    while(cin >> n){
        func(n);
        cout << "\n";
    }
}