#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> money) {
    vector<int> v(n+1, 0); v[0] = 1;
    for(auto k : money){
        for(int i=0;i<=n-k;i++){
            v[i+k] = (v[i+k] + v[i]) % 1000000007;
        }
    }
    return v[n];
}