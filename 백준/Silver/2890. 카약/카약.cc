#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int x,y; cin >> x >> y;
    char arr[x][y];
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            cin >> arr[i][j];
        }
    }

    int rank[10];
    map<int, set<int>> m;

    for(int i=0;i<x;i++){
        int cnt = 0;
        for(int j=y-2;j>0;j--){
            if(arr[i][j] == '.') cnt++;
            else{
                int num = arr[i][j] - '0';
                m[cnt].insert(num);
                break;
            }
        }
    }

    int award = 1;
    for(auto k : m){
        for(auto l : k.second){
            rank[l] = award;
        }
        award++;
    }

    for(int i=1;i<10;i++) cout << rank[i] << "\n";
    
    
    return 0;
}