#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <cmath>
#include <list>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    string s; cin >> s;
    list<char> li;
    for(auto a : s) li.push_back(a);
    int n; cin >> n;
    auto iter = li.end();
    for(int i=0;i<n;i++){
        char c; cin >> c;
        if(c == 'L'){
            if(iter != li.begin()) iter--;
        }
        else if(c == 'D'){
            if(iter != li.end()) iter++;
        }
        else if(c == 'B'){
            if(iter != li.begin()){
                auto iter_temp = iter--;
                li.erase(iter);
                iter = iter_temp;
            }
        }
        else if(c == 'P'){
            char temp; cin >> temp;
            li.insert(iter, temp);
        }
    }
    for(auto a : li)  cout << a;
    
    return 0;
}   