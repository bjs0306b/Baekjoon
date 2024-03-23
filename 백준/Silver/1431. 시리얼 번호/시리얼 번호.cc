#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <deque>
#include <set>
#include <cmath>
#include <queue>
using namespace std;

struct cmp{
    bool operator()(string a, string b){
        if(a.size() == b.size()){
            int suma = 0, sumb = 0;
            for(auto k : a){
                if(k > '0' && k <= '9'){
                    suma += k-'0';
                }
            }
            for(auto k : b){
                if(k > '0' && k <= '9'){
                    sumb += k-'0';
                }
            }
            if(suma == sumb) return a > b;
            return suma > sumb;
        }

        return a.size() > b.size();
    }
};

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    priority_queue<string, vector<string>, cmp> pq;
    for(int i=0;i<n;i++){
        string s; cin >> s;
        pq.push(s);
    }
    while(!pq.empty()){
        cout << pq.top() << '\n';
        pq.pop();
    }

    return 0;
}