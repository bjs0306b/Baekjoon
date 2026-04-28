#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    int arr[14]; for(int i=0;i<14;i++) cin >> arr[i];

    int BNP = n, TIM = n;   
    int BNPcnt = 0, TIMcnt = 0;

    for(int i=0;i<14;i++){
        if(arr[i] <= n){BNPcnt += n/arr[i]; BNP = n%arr[i]; break;}
    }
    BNP += BNPcnt*arr[13];

    for(int i=3;i<13;i++){
        if(arr[i] < arr[i-1] && arr[i-1] < arr[i-2] && arr[i-2] < arr[i-3]){ // down
            TIMcnt += TIM/arr[i];
            TIM = TIM%arr[i];
        }
        else if(arr[i] > arr[i-1] && arr[i-1] > arr[i-2] && arr[i-2] > arr[i-3]){ // up
            TIM += TIMcnt*arr[i];
            TIMcnt = 0;
        }
    }
    TIM += TIMcnt*arr[13];

    if(BNP > TIM) cout << "BNP";
    else if(BNP < TIM) cout << "TIMING";
    else cout << "SAMESAME";
    
    return 0;
}