#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n, cnt=0;
    cin >> n;
    int arr[100][100]; 
    for(int i=0;i<100;i++)
        for(int j=0;j<100;j++)
            arr[i][j]=0;
    for(int i=0;i<n;i++){
        int a,b; cin >>a>>b;
        for(int i=a;i<a+10;i++)
            for(int j=b;j<b+10;j++)
                arr[i][j] = 1;
    }
    for(int i=0;i<100;i++)
        for(int j=0;j<100;j++)
            if(arr[i][j] == 1) cnt++;
    cout << cnt;
    return 0;
}