#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <list>
#include <deque>
#include <set>
#include <cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    list<pair<int,int>> v;
    for(int i=1;i<=n;i++){
        int num; cin >> num;
        v.push_back({i,num});
    }
    auto iter = v.begin();
    while(!v.empty()){
        cout << iter->first << " ";
        int num = iter->second;
        auto temp = iter;
        iter++;
        v.erase(temp);  
        if(iter == v.end()) iter = v.begin();
        if(num < 0){
            for(int i=0;i<abs(num);i++){
                if(iter == v.begin()) iter = v.end();
                iter--;
            }
        }
        else if(num > 0){
            for(int i=0;i<num-1;i++){
                iter++;
                if(iter == v.end()) iter = v.begin();
            }
        }
        
    }
    return 0;
}