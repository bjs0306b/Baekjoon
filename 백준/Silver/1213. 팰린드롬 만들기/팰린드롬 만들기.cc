#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <deque>
#include <set>
#include <cmath>
using namespace std;

int arr[26];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    string s; cin >> s;
    for(auto k : s){
        arr[k-'A']++;  
    }
    int cnt = 0;
    vector<char> v,v2;
    for(int i=0;i<26;i++){
        if(arr[i]%2){
            for(int j=0;j<(arr[i]-1)/2;j++) v.push_back(i+'A');
            v2.push_back(i+'A');
        }
        else if(arr[i] > 0){
            for(int j=0;j<arr[i]/2;j++) v.push_back(i+'A');
        }
    }
    if(v2.size() > 1){
        cout << "I'm Sorry Hansoo";
    }
    else{
        for(auto k : v) cout << k;
        if(v2.size() == 1) cout << v2[0];
        for(auto k = v.rbegin();k!=v.rend();k++) cout << *k;
    }
    
    return 0;
}