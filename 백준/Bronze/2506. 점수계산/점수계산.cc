#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n; int arr[n];
    for(int i=0;i<n;i++) cin >>arr[i];
    int score = arr[0], stat = 1;
    for(int i=1;i<n;i++){
        if(arr[i]){
            if(arr[i-1]) stat++;
            score += stat;
        }
        else{
            stat = 1;
        }
    }
    cout << score;
}