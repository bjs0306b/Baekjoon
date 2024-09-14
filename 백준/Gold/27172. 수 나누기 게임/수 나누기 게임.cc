#include<bits/stdc++.h>
using namespace std;

pair<bool, int> check[1000001];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    int arr[n]; 
    for(int i=0;i<n;i++){
        int num; cin >> num;
        arr[i] = num;
        check[num].first = true;
    }
    for(int i=0;i<n;i++){
        int temp = arr[i];

        for(int j=1;j<=sqrt(temp);j++){
            if(temp % j == 0){
                if(check[j].first){
                    check[j].second++;
                    check[temp].second--;
                }
                if(temp != j*j && check[temp/j].first){
                    check[temp/j].second++;
                    check[temp].second--;
                }
            }
        }
    }

    for(int i=0;i<n;i++){
        cout << check[arr[i]].second << " ";
    }


    
    return 0;
}