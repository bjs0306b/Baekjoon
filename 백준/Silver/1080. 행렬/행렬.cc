#include <bits/stdc++.h>
using namespace std;
int n,m;
bool A[50][50], B[50][50], is_dif[50][50];

void input(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        string s; cin >> s;
        for(int j=0;j<m;j++){
            if(s[j] == '1') A[i][j] = true;
            else A[i][j] = false; 
        }
    }
     for(int i=0;i<n;i++){
        string s; cin >> s;
        for(int j=0;j<m;j++){
            if(s[j] == '1') B[i][j] = true;
            else B[i][j] = false; 
        }
    }
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(A[i][j] != B[i][j]) is_dif[i][j] = 1;
}

void reverse_func(int a, int b){
    for(int i=a;i<a+3;i++) for(int j=b;j<b+3;j++) is_dif[i][j] = !is_dif[i][j];
}

int ans(){

    bool flag = true;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(is_dif[i][j]) flag = false;
    if(flag) return 0;
    
    if(n < 3 || m < 3) return -1;

    int cnt = 0;
    for(int i=1;i<n-1;i++){
        for(int j=1;j<m-1;j++){
            if(is_dif[i-1][j-1]){
                reverse_func(i-1,j-1);
                cnt++;
            }
        }
    }

    for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(is_dif[i][j]) return -1;
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();
    cout << ans();
    
    return 0;
}