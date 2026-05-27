#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int cnt(string a, string b){
    int ret = 0;
    int b_size = b.size();
    for(int i=0;i<a.size();i++){
        if(i == b_size) return ret+1;
        if(a[i] == b[i]) ret++;
        else return ret+1;
    }
    return ret;
}

int solution(vector<string> words) {
    sort(words.begin(), words.end());
    int ret = 0;
    ret += cnt(words[0], words[1]);
    int size = words.size();
    ret += cnt(words[size-1], words[size-2]);
    
    for(int i=1;i<size-1;i++){
        ret += max(cnt(words[i], words[i-1]), cnt(words[i], words[i+1]));
    }
    return ret;
}