#include <string>
#include <vector>

using namespace std;

int ret_gcd(int a, int b){
    if(a % b) return ret_gcd(b, a%b);
    return b;
}

int solution(vector<int> arr) {
    int answer = arr[0];
    for(int i=1;i<arr.size();i++){
        int gcd = ret_gcd(answer, arr[i]);
        answer = arr[i] / gcd * answer;
    }
    return answer;
}