#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    string s; cin >> s;
    regex r("(100+1+|01)+");
    if(regex_match(s,r)) cout << "SUBMARINE";
    else cout << "NOISE";

    return 0;
}