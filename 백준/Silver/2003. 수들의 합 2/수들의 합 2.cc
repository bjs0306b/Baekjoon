#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int a,b; cin >>a>>b; int arr[a];
    for(int i=0;i<a;i++) cin >> arr[i];
    int cnt=0;
    for(int i=0;i<a;i++){
        int num = 0;
        for(int j=i;num < b; num+=arr[j],j++);
        if(num == b) cnt++;
    }
    cout << cnt;
    
    return 0;
}