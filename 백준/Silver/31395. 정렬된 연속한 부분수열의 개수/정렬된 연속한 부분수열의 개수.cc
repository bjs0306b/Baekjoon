#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    int arr[n];
    long long ans = 0;
    long long ascending_cnt = 1;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    for(int i=0;i<n-1;i++){
        if(arr[i] < arr[i+1]) ascending_cnt++;
        else{ans += (ascending_cnt)*(ascending_cnt+1)/2; ascending_cnt=1;}
    }

    ans += (ascending_cnt)*(ascending_cnt+1)/2;

    cout << ans;
    
    return 0;
}