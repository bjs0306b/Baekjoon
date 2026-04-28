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
    int n; cin >> n;
    while(n--){
        int a,b,sum=0; cin >> a >> b;
        int arr[a][b]; for(int i=0;i<a;i++) for(int j=0;j<b;j++) cin >> arr[i][j];
        for(int i=0;i<a;i++){
            for(int j=0;j<b;j++){
                if(arr[i][j]){
                    for(int k=i+1;k<a;k++){
                        if(!arr[k][j]) sum++;
                    }
                }
            }
        }
        cout << sum << "\n";
    }
    
    return 0;
}