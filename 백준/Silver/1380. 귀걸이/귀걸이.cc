#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; 
    int num = 0;
    for(;;){
        num++;
        cin >> n; cin.ignore(); if(n==0) break;

        string s[n]; for(int i=0;i<n;i++) getline(cin,s[i]);

        bool arr[n][2]; for(int i=0;i<n;i++) arr[i][0] = arr[i][1] = 0;

        for(int i=0;i<2*n-1;i++){
            int a; cin >> a;
            char b; cin >> b;
            arr[a-1][b-'A'] = 1;
        }


        for(int i=0;i<n;i++){
            if(arr[i][0] == 0 || arr[i][1] == 0) {cout << num << " " << s[i] << '\n'; break;}
        }
    }
    
    return 0;
}