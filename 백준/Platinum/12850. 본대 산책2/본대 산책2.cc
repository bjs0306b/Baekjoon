#include <bits/stdc++.h>
using namespace std;

int d;

vector<vector<long long>> A =
{
    {0, 1, 1, 0, 0, 0, 0, 0},
    {1, 0, 1, 1, 0, 0, 0, 0},
    {1, 1, 0, 1, 1, 0, 0, 0},
    {0, 1, 1, 0, 1, 1, 0, 0},
    {0, 0, 1, 1, 0, 1, 0, 1},
    {0, 0, 0, 1, 1, 0, 1, 0},
    {0, 0, 0, 0, 0, 1, 0, 1},
    {0, 0, 0, 0, 1, 0, 1, 0}
};
vector<vector<long long>> ans(8, vector<long long>(8));

void input(){
    cin >> d;

    for(int i=0;i<8;i++) ans[i][i] = 1; // 단위 행렬
}

vector<vector<long long>> multiply(vector<vector<long long>> a, vector<vector<long long>> b){
    vector<vector<long long>> temp(8, vector<long long>(8));
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            for(int k=0;k<8;k++){
                temp[i][j] += a[i][k] * b[k][j];
                temp[i][j] %= 1000000007;
            }
        }
    }
    return temp;
}

void solve(){
    while(d){
        if(d%2){
            ans = multiply(ans, A);
            d--;
        }
        A = multiply(A, A);
        d /= 2;
    }
    cout << ans[0][0]; // 0 -> 0 으로 d개의 선분을 지나 갈 수 있는 경우의 수
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    input();
    solve();

    return 0;
}