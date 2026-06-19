#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(int N, int number) {
    set<int> st[9];
    for(int i=1;i<9;i++){
        char c = '0' + N;
        string temp = string(i,c);
        int num = stoi(temp);
        if(num == number) return i;
        st[i].insert(num);
    }

    for(int i=2;i<9;i++){
        for(int j=1;j<i;j++){  
            for(auto k : st[j]){
                for(auto kk : st[i-j]){
                    if(k + kk == number) return i;
                    st[i].insert(k + kk);
                    if(k - kk == number) return i;
                    st[i].insert(k - kk);
                    if(kk != 0){
                        if(k / kk == number) return i;
                        st[i].insert(k / kk);
                    }
                        
                    if(k * kk == number) return i;
                    st[i].insert(k * kk);
                }
            }
        }
    }
    return -1;
}