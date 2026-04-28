#include<bits/stdc++.h>
using namespace std;

string to_bit(int n){
    string temp = "";
    while(n){
        if(n%2) temp += '1';
        else temp += '0';
        n/=2;
    }
    reverse(temp.begin(), temp.end());
    return temp;
}

int xor1(int a, int b){
    int ret = 0;
    int multiple = 1;
    string bita, bitb;
    bita = to_bit(a);
    bitb = to_bit(b);

    // cout << bita << " " << bitb << "\n";

    auto ritera = bita.rbegin();
    auto riterb = bitb.rbegin();

    while(ritera != bita.rend() && riterb != bitb.rend()){
        if(*ritera != *riterb) ret += multiple;
        multiple *= 2;
        ritera++; riterb++;
    }
    
    while(ritera != bita.rend()){
        if(*ritera == '1') ret += multiple;
        multiple *= 2;
        ritera++;
    }
    while(riterb != bitb.rend()){
        if(*riterb == '1') ret += multiple;
        multiple *= 2;
        riterb++;
    }

    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int a,b; cin >> a >> b;
    string c; cin >> c;
    bool flag = false;
    if((c[c.size()-1]-'0')%2) flag = true;


    if(flag){
        cout << xor1(a,b);
    }
    else cout << a;
    
    
    return 0;
}