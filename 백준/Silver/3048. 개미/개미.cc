#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int a,b; cin >> a >> b;
    deque<char> dq;
    for(int i=1;i<=a;i++){char c; cin >> c; dq.push_front(c);}
    for(int i=1;i<=b;i++){char c; cin >> c; dq.push_back(c);}
    int t; cin >> t;
    
    for(int i=0;i<t;i++){
        int cnt = (i+1-a)/2, cnt2 = (i+1-b);
        if(cnt < 0) cnt = 0;
        if(cnt2 < 0) cnt2 = 0;
        for(int j=0;j<=i-cnt2;j++){

            if(a-i-1+2*j >= 0 && a-i+j < a+b){
                if(cnt){cnt--;}
                else swap(dq[a-i-1+2*j],dq[a-i+2*j]); 
            }
        }
    }
    
    for(int i=0;i<a+b;i++) cout << dq[i];
    return 0;
}