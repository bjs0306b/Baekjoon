#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int a,b; cin >> a >> b;

    map<string, set<string>> m;

    for(int i=0;i<a;i++){
        string s; cin >> s;
        int num; cin >> num;

        for(int j=0;j<num;j++){
            string name; cin >> name;
            m[s].insert(name);
        }
    }

    for(int i=0;i<b;i++){
        string q; cin >> q;
        bool flag; cin >> flag;

        if(flag){
            for(auto k : m){
                set<string> member = k.second;
                if(member.find(q) != member.end()){
                    cout << k.first << "\n";
                    break;
                }
            }
        }
        else{
            set<string> member = m[q];
            for(auto k : member){
                cout << k << "\n";
            }
        }
    }
    
    
    return 0;
}