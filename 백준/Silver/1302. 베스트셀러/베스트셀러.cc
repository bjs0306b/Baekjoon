#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <set>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n;
    vector<string> v; set<string> s;
    for(int i=0;i<n;i++){
        string str; cin >> str;
        v.push_back(str); s.insert(str);
    }
    int max = 0;
    string max_string;
    for(auto a : s){
        int num = count(v.begin(), v.end(), a);
        if(max < num) {max = num; max_string = a;}
    }
    cout << max_string;
    
    return 0;
}