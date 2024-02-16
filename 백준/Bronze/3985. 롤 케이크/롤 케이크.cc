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
    int arr[n+1]; memset(arr, 0, 4*(n+1));
    int m; cin >>m;
    int mx=0, ans1;
   for(int i=1;i<m+1;i++){
        int a,b; cin >>a>>b;
        if(mx < b-a) {mx = b-a; ans1= i;}
        for(int j=a;j<=b;j++) if(arr[j]==0) arr[j] = i;
    }
    int mx2=0,ans2;
    for(int i=1;i<m+1;i++){
        int cnt = count(arr, arr+n+1, i);
        if(cnt > mx2) {mx2=cnt;ans2=i;}
    }
    cout << ans1 << "\n" << ans2;
    return 0;
}