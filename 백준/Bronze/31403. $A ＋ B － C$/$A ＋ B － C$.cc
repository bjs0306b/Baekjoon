#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    string a,b,c; cin >> a >> b >> c;
    int int_a = stoi(a), int_b = stoi(b), int_c = stoi(c);

    cout << int_a + int_b - int_c << "\n";

    a += b;

    cout << stoi(a) - int_c;
    
    return 0;
}