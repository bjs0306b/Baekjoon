#include <string>
#include <vector>
#include <algorithm>

using namespace std;


string solution(string X, string Y) {
    vector<int> cntX(10, 0), cntY(10, 0);
    for(auto k : X) cntX[k - '0']++;
    for(auto k : Y) cntY[k - '0']++;
    
    string ret = "";
    for(int i=9;i>=0;i--){
        for(int j=0;j<min(cntX[i], cntY[i]);j++){
            ret += (i + '0');
        }
    }
    if(ret == "") return "-1";
    for(int i=0;i<ret.size();i++){
        if(ret[i] != '0') return ret;
    }
    return "0";
}