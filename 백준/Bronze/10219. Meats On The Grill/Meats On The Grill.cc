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
    int n; cin >> n;
    while(n--){
        int a,b; cin >> a >> b;
        char arr[a][b];
        for(int i=0;i<a;i++)for(int j=0;j<b;j++)cin>>arr[i][j];
        for(int i=a-1;i>=0;i--){
            for(int j=0;j<b;j++){
                cout << arr[i][j];
            }
            cout << "\n";
        }
    }
    
    return 0;
}