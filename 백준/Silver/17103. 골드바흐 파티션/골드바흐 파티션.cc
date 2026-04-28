#include<bits/stdc++.h>
using namespace std;

bool sosu[1000001];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    for(int i=2;i<=1000000;i++) sosu[i] = 1;

    for(int i=2;i<=sqrt(1000000);i++){
        if(sosu[i]){
            for(int j=i*2;j<=1000000;j+=i){
                sosu[j] = 0;
            }
        }
    }

    int n; cin >> n;
    for(int i=0;i<n;i++){
        int num; cin >> num;
        int cnt = 0;

        for(int j=2;j<=num/2;j++){
            if(sosu[j] && sosu[num-j]) cnt++;
        }
        cout << cnt << "\n";
    }
    
    
    return 0;
}