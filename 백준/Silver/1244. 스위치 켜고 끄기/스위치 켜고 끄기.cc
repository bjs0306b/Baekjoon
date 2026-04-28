#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n;
    bool arr[n+1]; for(int i=1;i<n+1;i++) cin >> arr[i];
    int m; cin >> m;
    for(int i=0;i<m;i++){
        int a,b; cin >>a>>b;
        if(a==1){
            for(int j=b;j<n+1;j+=b)
                arr[j] = !arr[j];
        }
        else{
            arr[b] = !arr[b];
            for(int j=1;b-j>0&&b+j<=n;j++){
                if(arr[b-j] == arr[b+j]){ arr[b-j] = !arr[b-j],  arr[b+j] = !arr[b+j];}
                else break;
            }
        }
    }
    for(int i=1;i<n+1;i++) {cout << arr[i]<< " "; if((i)%20==0) cout << "\n";}
    
    return 0;
}