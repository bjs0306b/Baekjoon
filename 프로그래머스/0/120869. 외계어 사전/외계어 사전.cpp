#include <string>
#include <vector>

using namespace std;

int solution(vector<string> spell, vector<string> dic) {
    vector<int> alpha(26, 0);
    for(int i=0;i<spell.size();i++){
       int temp = spell[i][0] - 'a';
        alpha[temp]++;
    }
    
    for(int i=0;i<dic.size();i++){
        bool flag = true;
        vector<int> alpha_temp(26, 0);
        for(auto k : dic[i]){
            int temp = k - 'a';
            alpha_temp[temp]++;
        }
        
        for(int i=0;i<26;i++){
            if(alpha[i] == 1){
                if(alpha_temp[i] != 1){
                    flag = false;
                    break;
                }
            }
        }
        if(flag) return 1;
    }
    return 2;
}