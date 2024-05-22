#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    bool arr[n-1]; for(int i=0;i<n-1;i++) arr[i] = 0;
    for(int i=0;i<n;i++){
        int num; cin >> num;
        if(arr[num-1]) cout << num;
        else arr[num-1] = 1;
    }
    
    return 0;
}