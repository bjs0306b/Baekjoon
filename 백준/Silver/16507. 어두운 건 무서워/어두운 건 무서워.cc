#include <bits/stdc++.h>
using namespace std;

int n,m,q;
int A[1000][1000], pre_sum[1000][1000];
void input(){
    cin >> n >> m >> q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> A[i][j];
        }
    }

    pre_sum[0][0] = A[0][0];
    for(int i=1;i<n;i++) pre_sum[i][0] = pre_sum[i-1][0] + A[i][0];
    for(int i=1;i<m;i++) pre_sum[0][i] = pre_sum[0][i-1] + A[0][i];

    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            pre_sum[i][j] = pre_sum[i-1][j] + pre_sum[i][j-1] - pre_sum[i-1][j-1] + A[i][j];
        }
    }
}

void solve(){
    for(int i=0;i<q;i++){
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--,y1--,x2--,y2--;
        int temp = pre_sum[x2][y2], size = (x2-x1+1)*(y2-y1+1);
        if(x1 > 0) temp -= pre_sum[x1-1][y2];
        if(y1 > 0) temp -= pre_sum[x2][y1-1];
        if(x1 > 0 && y1 > 0) temp += pre_sum[x1-1][y1-1];
        
        cout << temp / size << "\n";
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    input();
    solve();

    return 0;
}