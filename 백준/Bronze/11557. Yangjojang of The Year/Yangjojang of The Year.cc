#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

class comp {
public:
    bool operator()(const pair<string, int>& a, const pair<string, int>& b) const {
        if (a.second != b.second) {
            return a.second > b.second;
        } else {
            return a.first < b.first;
        }
    }
};

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n;
    set<pair<string, int>, comp> se;
    for(int i=0;i<n;i++){
        int num; cin >> num;
        for(int j=0;j<num;j++){
            string s; cin >> s;
            int score; cin >> score;
            se.insert({s,score});
        }
        for(auto a : se){
            cout << a.first << "\n"; break;
        }
    }
    
    return 0;
}