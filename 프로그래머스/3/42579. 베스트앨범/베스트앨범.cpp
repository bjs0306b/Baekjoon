#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<string, int> cnt, use_cnt;

struct node{
    string genre;
    int idx, play;
    
    bool operator<(const node other){
        if(cnt[genre] == cnt[other.genre]){
            if(play == other.play) return idx < other.idx;
            return play > other.play;
        }
        return cnt[genre] > cnt[other.genre];
    }
};

vector<node> v;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> ret;
    int n = genres.size();
    cnt.clear();
    use_cnt.clear();
    for(int i=0;i<n;i++){
        cnt[genres[i]] += plays[i];
        v.push_back({genres[i], i, plays[i]});
    }
    
    sort(v.begin(), v.end());
    
    for(auto k : v){
        if(use_cnt[k.genre] == 2) continue;
        use_cnt[k.genre]++;
        ret.push_back(k.idx);
    }
    
    return ret;
}