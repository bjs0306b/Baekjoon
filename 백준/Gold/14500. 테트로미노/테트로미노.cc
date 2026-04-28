#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int a,b; cin >> a >> b;
    int arr[a][b]; for(int i=0;i<a;i++) for(int j=0;j<b;j++) cin >> arr[i][j];
    
    int mx = 0;

    /*

    ****

    */
    for(int i=0;i<a;i++){ //1
        for(int j=0;j<b-3;j++){
            int sum = arr[i][j] + arr[i][j+1] + arr[i][j+2] + arr[i][j+3];
            mx = max(mx , sum);
        }
    }

    for(int i=0;i<a-3;i++){ //2
        for(int j=0;j<b;j++){
            int sum = arr[i][j] + arr[i+1][j] + arr[i+2][j] + arr[i+3][j];
            mx = max(mx , sum);
        }
    }

    /*

    **
    **

    */

    for(int i=0;i<a-1;i++){ //1
        for(int j=0;j<b-1;j++){
            int sum = arr[i][j] + arr[i+1][j] + arr[i][j+1] + arr[i+1][j+1];
            mx = max(mx , sum);
        }
    }

    /*
    
    ***
      *
    
    */

   for(int i=0;i<a-1;i++){ //1
        for(int j=0;j<b-2;j++){
            int sum = arr[i][j] + arr[i][j+1] + arr[i][j+2] + arr[i+1][j+2];
            mx = max(mx , sum);
        }
    }

    for(int i=0;i<a-1;i++){ //2
        for(int j=0;j<b-2;j++){
            int sum = arr[i][j] + arr[i][j+1] + arr[i][j+2] + arr[i+1][j];
            mx = max(mx , sum);
        }
    }

    for(int i=0;i<a-1;i++){ //3
        for(int j=0;j<b-2;j++){
            int sum = arr[i][j] + arr[i+1][j] + arr[i+1][j+1] + arr[i+1][j+2];
            mx = max(mx , sum);
        }
    }

    for(int i=1;i<a;i++){ //4
        for(int j=0;j<b-2;j++){
            int sum = arr[i][j] + arr[i][j+1] + arr[i][j+2] + arr[i-1][j+2];
            mx = max(mx , sum);
        }
    }

    for(int i=0;i<a-2;i++){ //5
        for(int j=0;j<b-1;j++){
            int sum = arr[i][j] + arr[i+1][j] + arr[i+2][j] + arr[i][j+1];
            mx = max(mx , sum);
        }
    }

    for(int i=0;i<a-2;i++){ //6
        for(int j=0;j<b-1;j++){
            int sum = arr[i][j] + arr[i][j+1] + arr[i+1][j+1] + arr[i+2][j+1];
            mx = max(mx , sum);
        }
    }
    
    for(int i=0;i<a-2;i++){ //7
        for(int j=0;j<b-1;j++){
            int sum = arr[i][j] + arr[i+1][j] + arr[i+2][j] + arr[i+2][j+1];
            mx = max(mx , sum);
        }
    }

    for(int i=0;i<a-2;i++){ //8
        for(int j=1;j<b;j++){
            int sum = arr[i][j] + arr[i+1][j] + arr[i+2][j] + arr[i+2][j-1];
            mx = max(mx , sum);
        }
    }


    /*

     **
    **

    */

    for(int i=0;i<a-2;i++){ //1
        for(int j=0;j<b-1;j++){
            int sum = arr[i][j] + arr[i+1][j] + arr[i+1][j+1] + arr[i+2][j+1];
            mx = max(mx , sum);
        }
    }

    for(int i=0;i<a-2;i++){ //2
        for(int j=1;j<b;j++){
            int sum = arr[i][j] + arr[i+1][j] + arr[i+1][j-1] + arr[i+2][j-1];
            mx = max(mx , sum);
        }
    }
    
    for(int i=0;i<a-1;i++){ //3
        for(int j=0;j<b-2;j++){
            int sum = arr[i][j] + arr[i][j+1] + arr[i+1][j+1] + arr[i+1][j+2];
            mx = max(mx , sum);
        }
    }

    for(int i=1;i<a;i++){ //4
        for(int j=0;j<b-2;j++){
            int sum = arr[i][j] + arr[i][j+1] + arr[i-1][j+1] + arr[i-1][j+2];
            mx = max(mx , sum);
        }
    }

    /*
    
    ***
     *
    
    */

    for(int i=0;i<a-1;i++){ //1
        for(int j=0;j<b-2;j++){
            int sum = arr[i][j] + arr[i][j+1] + arr[i][j+2] + arr[i+1][j+1];
            mx = max(mx , sum);
        }
    }

    for(int i=1;i<a;i++){ //2
        for(int j=0;j<b-2;j++){
            int sum = arr[i][j] + arr[i][j+1] + arr[i-1][j+1] + arr[i][j+2];
            mx = max(mx , sum);
        }
    }

    for(int i=0;i<a-2;i++){ //3
        for(int j=0;j<b-1;j++){
            int sum = arr[i][j] + arr[i+1][j] + arr[i+1][j+1] + arr[i+2][j];
            mx = max(mx , sum);
        }
    }

    for(int i=0;i<a-2;i++){ //4
        for(int j=1;j<b;j++){
            int sum = arr[i][j] + arr[i+1][j] + arr[i+2][j] + arr[i+1][j-1];
            mx = max(mx , sum);
        }
    }

    cout << mx;

    return 0;
}