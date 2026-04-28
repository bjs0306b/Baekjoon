#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <deque>
#include <set>
#include <cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    cin.ignore();
    for(int i=1;i<=n;i++){
        cout << "Case #" << i << ": ";
        string s; getline(cin,s);
        string temp=""; vector<string> v;
        for(auto k : s){
            if(k == ' '){
                v.push_back(temp);
                temp = "";
            }
            else{
                temp += k;
            }
        }
        v.push_back(temp);

        while(!v.empty()){
            cout << v.back() << " ";
            v.pop_back();
        }
        cout << "\n";
    }
    
    return 0;
}
 