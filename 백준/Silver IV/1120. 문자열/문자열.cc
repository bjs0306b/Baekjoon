#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    string a,b; cin >>a>>b;
    int dif = b.size() - a.size();
    vector<int> v;
    for(int i=0;i<=dif;i++){
        int cnt = 0;
        for(int j=0;j<a.size();j++){
            if(a[j] == b[j+i]) cnt++;
        }
        v.push_back(cnt);
    }
    cout << a.size() - *max_element(v.begin(), v.end());
    
    
    return 0;
}