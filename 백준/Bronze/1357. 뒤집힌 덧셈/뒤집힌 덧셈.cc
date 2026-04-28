#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    string a,b; cin >>a>>b;
    reverse(a.begin(), a.end()); reverse(b.begin(), b.end());
    int aa = stoi(a); int bb = stoi(b);
    int cc = aa+bb; string c = to_string(cc);
    reverse(c.begin(), c.end());
    int p = stoi(c); cout << p;

    
    return 0;
}