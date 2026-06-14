#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int ret = 0;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    int size = B.size();
    int iter_B = 0;
    for(auto k : A){
        while(k >= B[iter_B]){
            iter_B++;
            if(iter_B == size) return ret;
        }
        ret++;
        iter_B++;
        if(iter_B == size) return ret;
    }
    
    return ret;
}