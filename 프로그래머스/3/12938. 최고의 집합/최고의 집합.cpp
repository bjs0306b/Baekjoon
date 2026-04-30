#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(int n, int s) {
    if(n > s) return {-1};
    
    vector<int> ret(n, s/n);

    int cnt = s - (s/n*n);
    for(int i=ret.size()-1;cnt>0;i--,cnt--){
        ret[i]++;
    }
 
    return ret;
}