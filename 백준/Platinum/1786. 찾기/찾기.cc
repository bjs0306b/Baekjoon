#include <bits/stdc++.h>
using namespace std;

string a,b;
vector<int> table;
vector<int> ans_pos;
int cnt = 0;

void makeTable(){
    int bsize = b.size();
    int j = 0;
    table.resize(bsize);
    for(int i=1;i<bsize;i++){
        while(j > 0 && b[i] != b[j]) j = table[j-1];
        if(b[i] == b[j]) table[i] = ++j;
    }
}

void input(){
    getline(cin, a);
    getline(cin, b);
}

void kmp(){
    int asize = a.size(), bsize = b.size();
    int j = 0;
    for(int i=0;i<asize;i++){
        while(j > 0 && a[i] != b[j]) j = table[j-1];
        if(a[i] == b[j]){
            if(j == bsize - 1){
                cnt++;
                ans_pos.push_back(i - bsize + 2);
                j = table[j];
            }
            else j++;
        }
    }
}

void solve(){
    makeTable();
    kmp();
    cout << cnt << "\n";
    for(auto k : ans_pos) cout << k << " ";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    
    input();
    solve();

    return 0;
}