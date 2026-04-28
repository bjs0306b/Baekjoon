#include<bits/stdc++.h>
using namespace std;

struct cmp{
    bool operator()(string a, string b){
        if(a.size() == b.size()) return a > b;
        return a.size() > b.size();
    }
};

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int a,b; cin >> a >> b;
    priority_queue<string, vector<string>, cmp> pq[a];
    
    int n;
    string name;
    for(;;){
        cin >> n >> name;
        if(n==0 && name=="0") break;
        if(pq[n-1].size() != b) pq[n-1].push(name);
    }

    for(int j=0;j<=1;j++){
        for(int i=j;i<a;i+=2){
            while(!pq[i].empty()){
                cout << i+1;
                string temp = pq[i].top();
                pq[i].pop();
                cout << " " << temp << "\n";
            }
        }
    }
    

    return 0;
}