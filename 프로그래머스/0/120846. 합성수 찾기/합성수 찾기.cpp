#include <string>
#include <vector>

using namespace std;

int cnt(int n){
    int ret = 0;
    for(int i=1;i<=n;i++){
        if(n % i == 0) ret++;
    }
    return ret;
}

int solution(int n) {
    int ret = 0;
    for(int i=1;i<=n;i++){
        if(cnt(i) > 2) ret++;
    }
    return ret;
}