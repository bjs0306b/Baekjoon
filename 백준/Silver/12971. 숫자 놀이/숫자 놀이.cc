#include<bits/stdc++.h>
using namespace std;

// bool disjoint(int a, int b, int c){
    
// }

// int main(){
//     ios_base::sync_with_stdio(0);cin.tie(0);
//     int p1,p2,p3,x1,x2,x3; cin >> p1 >> p2 >> p3 >> x1 >> x2 >> x3;

//     if(x1==x2 && x2==x3){cout << x1; return 0;}
//     if()

//     int n1 = p2*p3, n2 = p1*p3, n3 = p1*p2;
//     int n1_p = n1, n2_p = n2, n3_p = n3;
//     while(n1%p1!=1){
//         n1 += n1_p;
//     }
//     while(n2%p2!=1){
//         n2 += n2_p;
//     }while(n3%p3!=1){
//         n3 += n3_p;
//     }

//     int x = x1*n1 + x2*n2 + x3*n3;
//     int m = p1*p2*p3;
//     int ans = x%m;
//     cout << ans;
//     return 0;
// }

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int p1,p2,p3,x1,x2,x3; cin >> p1 >> p2 >> p3 >> x1 >> x2 >> x3;
    
    for(int i=x1;i<=p1*p2*p3+x1;i+=p1){
        if(i%p1==x1 && i%p2==x2 && i%p3==x3){
            cout << i;
            return 0;
        }
    }
    cout << -1;
    
    return 0;
}