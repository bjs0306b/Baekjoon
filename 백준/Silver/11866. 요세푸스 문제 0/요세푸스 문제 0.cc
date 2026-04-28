#include <iostream>
#include <vector>
using namespace std;
int a[1002];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int m,n;
    cin >> m >> n;
    int arr=0, cnt=0, num=0;
    for(int i=0;i<1002;i++) a[i]=1;
    cout << "<";
    while(cnt != m-1){
        arr++;
        if(a[arr] == 0) continue;
        if(arr == m+1) {arr = 0; continue;}

        num++;
        if(num == n){
            a[arr] = 0;
            cout << arr << ", ";
            num = 0;
            cnt++;
        }
    }
    for(int i=1;i<m+1;i++){
        if(a[i] == 1){
            cout << i << ">";
            break;
        }
    }

    return 0;
}