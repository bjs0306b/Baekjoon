#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    int arr[n][3];
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            cin >> arr[i][j];
        }
    }

    int dp_min[3], dp_max[3];
    for(int i=0;i<3;i++){   
        dp_min[i] = arr[0][i];
        dp_max[i] = arr[0][i];
    }

    for(int i=1;i<n;i++){
        int prev_min[3] = {dp_min[0], dp_min[1], dp_min[2]};
        int prev_max[3] = {dp_max[0], dp_max[1], dp_max[2]};

        dp_min[0] = min(prev_min[0] + arr[i][0], prev_min[1] + arr[i][0]);
        dp_min[1] = min({prev_min[0] + arr[i][1], prev_min[1] + arr[i][1], prev_min[2] + arr[i][1]});
        dp_min[2] = min(prev_min[1] + arr[i][2], prev_min[2] + arr[i][2]);

        dp_max[0] = max(prev_max[0] + arr[i][0], prev_max[1] + arr[i][0]);
        dp_max[1] = max({prev_max[0] + arr[i][1], prev_max[1] + arr[i][1], prev_max[2] + arr[i][1]});
        dp_max[2] = max(prev_max[1] + arr[i][2], prev_max[2] + arr[i][2]);
    }
    
    cout << *max_element(dp_max, dp_max + 3) << " " << *min_element(dp_min, dp_min + 3);
    return 0;
}