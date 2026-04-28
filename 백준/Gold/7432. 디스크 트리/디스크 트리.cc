#include <bits/stdc++.h>
using namespace std;

struct node{
    map<string, node*> child;
};  

node* head;
int n;

void input(){
    cin >> n;
    head = new node();

    for(int i=0;i<n;i++){
        string s; cin >> s;

        node* cur = head;

        string temp = "";
        for(int j=0;j<s.size();j++){
            if(s[j] == '\\'){
                if(cur->child.find(temp) == cur->child.end()){
                    cur->child[temp] = new node();
                }
                cur = cur->child[temp];
                temp = "";
            }
            else temp += s[j];
        }
        if(cur->child.find(temp) == cur->child.end()){
            cur->child[temp] = new node();
        }
    }
}

void dfs(node* cur, int dep){
    for(auto k : cur->child){
        for(int i=0;i<dep;i++) cout << " ";
        cout << k.first << "\n";
        dfs(k.second, dep+1);
    }
}

void solve(){
    dfs(head, 0);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    input();
    solve();

    return 0;
}