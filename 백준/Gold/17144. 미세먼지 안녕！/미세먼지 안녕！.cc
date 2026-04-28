#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a, b, t;
    cin >> a >> b >> t;
    int arr[a][b];
    int sum = 0;
    int ac1=-1, ac2=-1;
    for (int i = 0; i < a; i++){
        for (int j = 0; j < b; j++){
            cin >> arr[i][j];
            if(arr[i][j] == -1){
                if(ac1 == -1) ac1 = i, ac2 = i+1;   
            }
            else sum += arr[i][j];
        }
    }
    
    while(t--){
        int copy[a][b];
        for(int i=0;i<a;i++) for(int j=0;j<b;j++) copy[i][j] = 0;
        copy[ac1][0] = copy[ac2][0] = -1;

        for(int i=0;i<a;i++){
            for(int j=0;j<b;j++){
                if(j !=0 || i != ac1 && i != ac2){
                // if(!(i == ac1 && j == 0 || i == ac2 && j == 0)){
                    int temp = arr[i][j] / 5;
                    int cnt = 0;
                    if(i > 0 && arr[i-1][j] != -1){copy[i-1][j] += temp; cnt++;}
                    if(j > 0 && arr[i][j-1] != -1){copy[i][j-1] += temp; cnt++;}
                    if(i < a-1 && arr[i+1][j] != -1){copy[i+1][j] += temp; cnt++;}
                    if(j < b-1 && arr[i][j+1] != -1){copy[i][j+1] += temp; cnt++;}
                    copy[i][j] += arr[i][j] - cnt * temp;
                }
            }
        }
        sum -= copy[ac1-1][0];
        for(int i=ac1-2; i>=0; i--) copy[i+1][0] = copy[i][0];
        for(int i=1;i<b;i++) copy[0][i-1] = copy[0][i];
        for(int i=0;i<ac1;i++) copy[i][b-1] = copy[i+1][b-1];
        for(int i=b-1;i>1;i--) copy[ac1][i] = copy[ac1][i-1];
        copy[ac1][1] = 0;

        sum -= copy[ac2+1][0];
        for(int i=ac2+1;i<a-1;i++) copy[i][0] = copy[i+1][0];
        for(int i=0;i<b-1;i++) copy[a-1][i] = copy[a-1][i+1];
        for(int i=a-1;i>ac2;i--) copy[i][b-1] = copy[i-1][b-1];
        for(int i=b-1;i>1;i--) copy[ac2][i] = copy[ac2][i-1];
        copy[ac2][1] = 0;
        


        for(int i=0;i<a;i++) for(int j=0;j<b;j++) arr[i][j] = copy[i][j];
    }

    // for (int i = 0; i < a; i++){
    //     for (int j = 0; j < b; j++){
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << '\n';
    // }
    cout << sum;
    return 0;
}