#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <deque>
#include <set>
#include <cmath>
#include <map>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n,k; cin >> n >> k;
    map<int,int> mp, temp; 
    int max = 0;
    for(int i=0;i<n;i++){
        int w,v; cin >> w >> v;
        temp = mp;
        if(w <= k){
            for(auto a : mp){
                if(a.first + w <= k){
                    if(temp.find(a.first + w) == temp.end()){
                        temp.insert({a.first + w, a.second + v});
                    }
                    else{
                        if(temp[a.first + w] < a.second + v){
                            temp[a.first + w] = a.second + v;
                        }
                    }
                } 
            }
            if(temp.find(w) == temp.end() || temp[w] < v) temp[w] = v;
        }
        mp = temp;
    }
    for(auto a : mp){
        if(a.second > max) max = a.second;
    }
    cout << max;
    
    return 0;
}