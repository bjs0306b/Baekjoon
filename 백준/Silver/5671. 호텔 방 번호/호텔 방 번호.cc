#include<bits/stdc++.h>
using namespace std;

bool func(int n){
    string str = to_string(n);
    bool arr[10]; fill(arr,arr+10,false);
    for(int i=0;i<str.size();i++){
        if(arr[str[i]-'0']) return false;
        arr[str[i]-'0'] = true;
    }
    return true;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    int a,b;

    while(cin >> a >> b){
        int cnt = 0;
        for(int i=a;i<=b;i++){
            if(func(i)) cnt++;
        }
        cout << cnt << "\n";
    }
    
    return 0;
}