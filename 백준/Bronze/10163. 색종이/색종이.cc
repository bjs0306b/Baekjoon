#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
using namespace std;
int arr[1001][1001];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n; int cnt[n+1]; 
    for(int i=1;i<=n;i++){
        cnt[i] = 0;
        int x1,y1,x2,y2; cin >>x1>>y1>>x2>>y2;
        for(int j=x1;j<x1+x2;j++){
            for(int k=y1;k<y1+y2;k++){
                arr[j][k]=i;
            }
        }
    }
    for(int i=0;i<1001;i++){
        for(int j=0;j<1001;j++){
            if(arr[i][j] > 0) cnt[arr[i][j]]++;
        }
    }
    for(int i=1;i<=n;i++) cout << cnt[i] << "\n";
    
    return 0;
}