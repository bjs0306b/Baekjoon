#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    while(n--){
        int num; cin >> num;
        int sum = 0;
        int arr[num]; for(int i=0;i<num;i++){cin >> arr[i]; sum += arr[i];}
        int mx = 0, mx_cnt = 0, mx_idx;

        for(int i=0;i<num;i++){
            if(arr[i] > mx){
                mx = arr[i];
                mx_cnt = 1;
                mx_idx = i;
            }
            else if(arr[i] == mx) mx_cnt++;
        }

        if(mx_cnt > 1) cout << "no winner\n";
        else if(mx > sum/2) cout << "majority winner " << mx_idx+1 << "\n";
        else cout << "minority winner " << mx_idx+1 << "\n";
    }
    
    return 0;
}