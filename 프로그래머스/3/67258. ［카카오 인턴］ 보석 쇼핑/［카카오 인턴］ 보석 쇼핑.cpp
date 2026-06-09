#include <string>
#include <vector>
#include <set>
#include <map>
#include <deque>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> gems) {
    map<string, int> m;
    set<string> st; for(auto k : gems) st.insert(k);
    int n = st.size();
    
    for(auto k : st) m[k] = 0;
    int cnt = 0;
    vector<int> answer = {0, 1000000000};
    
    int s = 1;
    int e = 0;
    deque<string> dq;
    for(auto k : gems){
        
        dq.push_back(k);
        e++;
        if(m[k]++ == 0) cnt++;
        if(cnt == n){
            cout << s << " " << e << "\n";
            
            while(cnt == n){
                string temp = dq.front();
                dq.pop_front();
                s++;
                if(--m[temp] == 0){
                    if(e - (s - 1) < answer[1] - answer[0]){
                        answer = {s-1, e};
                    }
                    cnt--;
                }
            }
        }
    }
    
    return answer;
}