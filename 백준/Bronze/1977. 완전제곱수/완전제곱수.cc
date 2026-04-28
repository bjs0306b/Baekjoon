#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int a,b,sum=0; cin >>a>>b;
    vector<int> v;
    for(int i=1;i*i<=b;i++){
        if(a <= i*i) {sum+=i*i;v.push_back(i*i);}
    }
    if(v.size()) cout << sum << "\n"<<v[0];
    else cout << "-1";
    
    return 0;
}