#include <string>
#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int N;
int A[5] = {0,1,2,2,3};
int B[5] = {1,1,0,1,1};
int sum[2];
int fours[21];
deque<int> dq[2];

void dfs(int dep, int idx){
    if(dep == N-1){
        sum[idx] += A[dq[idx][dep]] + B[dq[idx][dep]];
        return;
    }
    sum[idx] += A[dq[idx][dep]] * fours[N-dep-1];
    if(dq[idx][dep] == 2) return;
    dfs(dep+1, idx);
}

int solution(int n, long long l, long long r) {
    N = n;
    long long temp[2];
    temp[0] = l-2, temp[1] = r-1;
    fours[0] = 1;
    for(int i=1;i<21;i++){
        fours[i] = 4 * fours[i-1];
    }

    for(int j=0;j<2;j++){
        for(int i=0;i<n;i++){
            dq[j].push_front(temp[j]%5);
            temp[j] /= 5;
        }
    }
    
    for(int i=0;i<2;i++) dfs(0, i);
    cout << sum[0] << " " << sum[1];
    return sum[1] - sum[0];
}