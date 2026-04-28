#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <set>
#include <cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    int arr[n][3];
    for(int i=0;i<n;i++) for(int j=0;j<3;j++) cin >> arr[i][j];
    int score[n]; memset(score, 0, 4*n);
    for(int i=0;i<3;i++){
        vector<int> v;
        for(int j=0;j<n;j++) v.push_back(arr[j][i]);
        for(int j=0;j<n;j++){
            if(count(v.begin(), v.end(), arr[j][i]) == 1) score[j] += arr[j][i];
        }
        v.clear();
    }
    for(int i=0;i<n;i++) cout << score[i] << "\n";
    
    return 0;
}