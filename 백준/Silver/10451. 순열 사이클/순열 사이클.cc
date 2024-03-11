#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <deque>
#include <set>
#include <cmath>
using namespace std;
int arr[1001][1001];
bool visited[1001];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    while(n--){
        int num; cin >> num;
        memset(visited,0,sizeof(visited));
        memset(arr,0,sizeof(arr));
        for(int i=1;i<=num;i++){
            int temp; cin >> temp;
            arr[i][temp] = 1;
        }
        int ans = 0;
        for(int i=1;i<=num;i++){
            if(visited[i] == false){
                int temp2 = i;
                visited[i] = true;
                for(;;){
                    int temp;
                    for(int j=1;j<=num;j++){
                        if(arr[temp2][j] == 1){
                            temp = j;
                            break;
                        }
                    }
                    if(visited[temp] == false){
                        visited[temp] = true;
                        temp2 = temp;
                    }
                    else{
                        ans++;
                        break;
                    }
                }
            }
        }
        cout << ans << "\n";
    }
    
    return 0;
}