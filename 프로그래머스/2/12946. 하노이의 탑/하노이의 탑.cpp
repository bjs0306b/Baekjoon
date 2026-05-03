#include <string>
#include <vector>

using namespace std;
vector<vector<int>> answer;

void hanoi(int size, int s, int e, int m){
    if(size == 1){
        answer.push_back({s, e});
        return;
    }
    hanoi(size-1, s, m, e);
    answer.push_back({s, e});
    hanoi(size-1, m, e, s);
}

vector<vector<int>> solution(int n) {
    hanoi(n, 1, 3, 2);
    
    return answer;
}