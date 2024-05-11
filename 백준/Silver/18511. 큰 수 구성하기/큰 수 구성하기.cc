#include<bits/stdc++.h>
using namespace std;

int n,k;
int sz;
int arr[4];
int ans;
void func(int num, int cnt, bool zero){
    if(cnt == sz){
        if(num <= n && ans < num) ans = num;
        return;
    }
    for(int i=0;i<=k;i++){
        if(i==0 && !zero) continue;
        if(i != 0) zero = 0;

        func(num*10+arr[i], cnt+1, zero);
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> k;
    sz = to_string(n).size();
    for(int i=1;i<=k;i++) cin >> arr[i];
    arr[0] = 0;
    sort(arr, arr+k+1);
    func(0,0,1);

    cout << ans;
    return 0;
}