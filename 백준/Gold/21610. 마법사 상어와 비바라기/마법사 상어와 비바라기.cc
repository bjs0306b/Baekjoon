#include <bits/stdc++.h>
using namespace std;

int n,m;
int A[50][50];
bool cloud[50][50];

void step4(int x, int y){
    int dx[4] = {-1,-1,1,1}, dy[4] = {1,-1,1,-1};
    for(int i=0;i<4;i++){
        if(x + dx[i] >= 0 && x + dx[i] < n && y + dy[i] >=0 && y + dy[i] < n){
            if(A[x+dx[i]][y+dy[i]]) A[x][y]++;
        }
    }
}

void step1(int d, int s){
    // step1
    d--;
    s = s%n;
   int dx[8] = {0,-1,-1,-1,0,1,1,1}, dy[8] = {-1,-1,0,1,1,1,0,-1};

   int temp[n][n]; for(int i=0;i<n;i++) for(int j=0;j<n;j++) temp[i][j] = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(cloud[i][j]){
                cloud[i][j] = 0;
                temp[(i+dx[d]*s+n)%n][(j+dy[d]*s+n)%n] = 1;
            }
        }  
    }
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cloud[i][j] = temp[i][j];
    
    // step2
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(cloud[i][j]){
                A[i][j]++;
            }
        }  
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(cloud[i][j]){
                step4(i,j); // step4
            }
        }  
    }

    for(int i=0;i<n;i++){ // step3, step5
        for(int j=0;j<n;j++){
            if(cloud[i][j]){
               cloud[i][j] = 0;
            }
            else{
                if(A[i][j] > 1){
                    cloud[i][j] = 1;
                    A[i][j] -= 2;
                }
            }
        }  
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;

    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin >> A[i][j];
    cloud[n-1][0] = cloud[n-1][1] = cloud[n-2][0] = cloud[n-2][1] = 1;
    for(int i=0;i<m;i++){
        int a,b; cin >> a >> b;
        step1(a,b);
    }

    int sum = 0;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) sum += A[i][j];
    cout << sum;


    return 0;
}