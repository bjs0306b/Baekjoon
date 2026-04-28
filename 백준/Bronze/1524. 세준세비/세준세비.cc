#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    while(n--){
        int s,b; cin >> s >> b;

        deque<int> ss, bb;
        for(int i=0;i<s;i++){int num; cin >> num; ss.push_back(num);}
        for(int i=0;i<b;i++){int num; cin >> num; bb.push_back(num);}

        sort(ss.begin(), ss.end());
        sort(bb.begin(), bb.end());

        while(ss.size() && bb.size()){
            if(ss.front() < bb.front()) ss.pop_front();
            else bb.pop_front();
        }

        if(ss.size()) cout << "S\n";
        else cout << "B\n";
    }
    
    return 0;
}