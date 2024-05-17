#include<bits/stdc++.h>
using namespace std;
bool arr[6][6];
int prea,preb;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    bool flag = 1;
    char fa,fb; cin >> fa >> fb;
    prea = fa; preb = fb;
    arr[fa-'A'][fb-'1'] = 1;
    for(int i=1;i<36;i++){
        char a,b; cin >> a >> b;
        if(!((abs(prea - a) == 2 && abs(preb - b) == 1) || (abs(prea - a) == 1 && abs(preb - b) == 2))) flag = 0;
        if(arr[a-'A'][b-'1']) flag = 0;
        else arr[a-'A'][b-'1'] = 1;
        prea = a; preb = b;

        if(i == 35){
            if(!((abs(prea - fa) == 2 && abs(preb - fb) == 1) || (abs(prea - fa) == 1 && abs(preb - fb) == 2))) flag = 0;
        }
    }
    if(flag) cout << "Valid";
    else cout << "Invalid";
    
    
    return 0;
}