#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    if(a % b) return gcd(b, a%b);
    return b;
}

pair<int,int> func(int a, int b, int c, int d){
    int n1 = a*d - b*c, n2 = b*d;
    int g = gcd(n1, n2);
    n1 /= g, n2 /= g;
    return {n1,n2};
}

void solve(){
    int a,b;
    cin >> a >> b;
    if(a == 1){
        cout << b << "\n";
        return;
    }
    for(;;){
        auto temp = func(a,b,1,(b+a-1)/a);
        if(temp.first == 1){
            cout << temp.second << "\n";
            return;
        }
        a = temp.first, b = temp.second;
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}