#include <string>
#include <vector>

using namespace std;

vector<string> user, ban;
int n, ans;
bool visited[1<<8][8];

bool checked(string a, string b){
    if(a.size() != b.size()) return false;
    for(int i=0;i<a.size();i++){
        if(b[i] == '*') continue;
        if(a[i] != b[i]) return false;
    }
    return true;
}

void dfs(int dep,int visit){
    if(visited[visit][dep]) return;
    visited[visit][dep] = true;
    if(dep == n){
        ans++;
        return;
    }
    for(int i=0;i<user.size();i++){
        if((visit & (1<<i)) != 0) continue;
        if(!(checked(user[i], ban[dep]))) continue;
        dfs(dep+1, visit | (1<<i));
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    n = banned_id.size();
    user = user_id, ban = banned_id;
    ans = 0;
    dfs(0, 0);

    return ans;
}