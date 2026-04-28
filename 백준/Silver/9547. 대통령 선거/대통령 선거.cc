#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    for(int i=0;i<n;i++){
        int C,V; cin >> C >> V;
        int arr[V][C];
        for(int j=0;j<V;j++){
            for(int k=0;k<C;k++){
                cin >> arr[j][k];
            }
        }

        int vote[C]; memset(vote, 0, sizeof(int)*C);

        for(int j=0;j<V;j++){
            vote[arr[j][0]-1]++;
        }

        bool flag = false;
        for(int j=0;j<C;j++){
            if(vote[j] > V/2){
                cout << j+1 << " 1\n";
                flag = true; break;
            }
        }  
        if(flag) continue;

        int first = max_element(vote, vote+C) - vote + 1;
        int second;
        int mx_num = 0;
        for(int j=0;j<C;j++){
            if(mx_num < vote[j] && j != first - 1){
                mx_num = vote[j];
                second = j+1;
            } 
        }

        // cout << first << " " << second << '\n';

        int score[2]; memset(score, 0, 8);

        for(int j=0;j<V;j++){
            for(int k=0;k<C;k++){
                if(arr[j][k] == first){score[0]++; break;}
                else if(arr[j][k] == second){score[1]++; break;}
            }
        }

        if(score[0] > score[1]) cout << first << " 2\n";
        else cout << second << " 2\n";
        
    }
    
    return 0;
}