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
    
    while(n--){
        vector<char> v;
        string s1,s2; cin >> s1 >> s2;
        if(s1.size() < s2.size()) swap(s1,s2);
        auto iter1 = s1.rbegin(), iter2 = s2.rbegin();
        for(int i=0;i<s2.size();i++){
            char temp = *iter1++ - '0' + *iter2++;
            v.push_back(temp);
        }
        for(int i=s2.size();i<s1.size();i++){
            v.push_back(*iter1++);
        }
        for(int i=0;i<v.size();i++){
            if(v[i] > '1'){
                v[i] -= 2;
                if(i == v.size()-1) v.push_back('1');
                else     
                    v[i+1]++;
            }
        }
        bool check = false;
        while(!v.empty()){
            if(v.back() != '0') check = true;
            if(check) cout << v.back();
            v.pop_back();
        }
        if(!check) cout << "0";
        cout << "\n";
    }
    
    return 0;
}

