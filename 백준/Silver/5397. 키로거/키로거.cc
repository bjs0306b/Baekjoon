#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <deque>
#include <set>
#include <list>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    while(n--){
        list<char> l;
        string s; cin >> s;
        bool check = true;
        list<char>::iterator iter;
        for(auto k : s){
            if(check){
                if(k != '<' && k != '>' && k != '-'){
                    l.push_back(k);
                    check = false;
                    iter = l.end();
                }
            }
            else{
                if(k == '<'){
                    if(iter != l.begin())
                        iter--;
                }
                else if(k == '>'){
                    if(iter != l.end())
                        iter++; 
                }
                else if(k == '-'){
                    if(iter != l.begin()){
                        auto temp = iter;
                        l.erase(--temp);
                    }
                }
                else{
                    l.insert(iter,k);
                }
            }
        }
        for(auto k : l) cout << k;
        cout << "\n";
    }
    
    return 0;
}