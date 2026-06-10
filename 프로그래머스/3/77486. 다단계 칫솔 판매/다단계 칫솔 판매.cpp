#include <string>
#include <vector>
#include <map>

using namespace std;

map<string, string> par;
map<string, int> sum;

void dfs(string s, int left_money){
    if(left_money == 0) return;
    
    dfs(par[s], left_money / 10);
    
    left_money -= left_money / 10;
    sum[s] += left_money;
}

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    par.clear();
    sum.clear();
    for(int i=0;i<enroll.size();i++){
        par[enroll[i]] = referral[i];
        sum[enroll[i]] = 0;
    }
    
    for(int i=0;i<seller.size();i++){
        dfs(seller[i], amount[i]*100);
    }
    
    vector<int> ret;
    for(int i=0;i<enroll.size();i++){
        ret.push_back(sum[enroll[i]]);
    }
    return ret;
}