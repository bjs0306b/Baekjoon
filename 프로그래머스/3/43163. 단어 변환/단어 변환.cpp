#include <string>
#include <vector>
#include <queue>

using namespace std;

int cnt_dif_alp(string a, string b){
    int cnt = 0;
    for(int i=0;i<a.size();i++){
        if(a[i] != b[i]) cnt++;
    }
    return cnt;
}

int solution(string begin, string target, vector<string> words) {
    int n = words.size();
    n++;
    bool has_edge[n][n];
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) has_edge[i][j] = false;
    for(int i=0;i<n-1;i++){
        if(cnt_dif_alp(begin, words[i]) == 1){
            has_edge[0][i+1] = true;
            has_edge[i+1][0] = true;
        }
    }
    
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1;j++){
            if(i != j && cnt_dif_alp(words[i], words[j]) == 1){
                has_edge[i+1][j+1] = true;
                has_edge[j+1][i+1] = true;
            }
        }
    }
    
    int target_idx = -1;
    for(int i=0;i<n-1;i++){
        if(words[i] == target){
            target_idx = i+1;
            break;
        }
    }
    if(target_idx == -1) return 0;
    
    int ret = 0;
    queue<int> q; q.push(0);
    vector<bool> visited(n+1, false);
    
    while(!q.empty()){
        int size = q.size();
        for(int i=0;i<size;i++){
            int f = q.front(); q.pop();
            if(f == target_idx) return ret;
            for(int j=0;j<n+1;j++){
                if(!visited[j] && has_edge[f][j]){
                    q.push(j);
                    visited[j] = true;
                }
            }
        }
        ret++;
    }
    return 0;
}