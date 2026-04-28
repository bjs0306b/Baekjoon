#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <deque>
#include <set>
#include <cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int a,b; cin >> a >> b;
    char arr[a][b]; for(int i=0;i<a;i++) for(int j=0;j<b;j++) cin >> arr[i][j];
    int ans[a][b];
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            if(arr[i][j] == 'c') cout << 0 << " ";
            else{
                int temp= j, cnt=0;
                bool check = false;
                for(;;){
                    if(arr[i][temp] == 'c'){
                        cout << cnt << " ";
                        check = true;
                    }
                    temp--; cnt++;
                    if(check) break;
                    if(temp == -1) break;
                }
                if(check == false) cout << -1 << " ";
            }
        }
        cout << "\n";
    }
    
    return 0;
}