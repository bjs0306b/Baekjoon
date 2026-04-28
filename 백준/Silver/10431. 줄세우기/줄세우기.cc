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
    int n; cin >> n;
    for(int i=1;i<=n;i++){
        int num,cnt=0; cin >> num; cout << num << " ";
        int arr[20]; for(int j=0;j<20;j++) cin >> arr[j];
        for(int j=0;j<20;j++){
            for(int k=0;k<19;k++){
                if(arr[k] > arr[k+1]){
                    swap(arr[k], arr[k+1]);
                    cnt++;
                }
            }
        }
        cout << cnt << "\n";
    }
    
    return 0;
}

