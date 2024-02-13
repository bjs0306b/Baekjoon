#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
using namespace std;
bool arr[1001][1001], visited[1001];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int a,b; cin >>a>>b;
        for(int j=0;j<b;j++){
            int c,d; cin >>c>>d;
            arr[c][d]=1, arr[d][c]=1;
        }
        cout << a-1 << "\n";
    }
    
    return 0;
}