#include<bits/stdc++.h>
using namespace std;

int arr[1001][1001];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    string s1,s2; cin >> s1 >> s2;

    set<int> s[26];
    for(int i=0;i<s2.size();i++)
        s[s2[i]-'A'].insert(i);
    
    for(auto k : s[s1[0]-'A']){
        for(int i=k;i<s2.size();i++) arr[0][i] = 1;
        break;
    }

    for(int i=1;i<s1.size();i++){
        for(auto k : s[s1[i] - 'A']){
            arr[i][k] = arr[i-1][k-1] + 1;
        }
        int temp = arr[i][0];
        for(int j=1;j<s2.size();j++){
            if(temp < arr[i][j]) temp = arr[i][j];
            arr[i][j] = temp;
        }
        for(int j=0;j<s2.size();j++){
            arr[i][j] = max(arr[i-1][j] , arr[i][j]);
        }
    }

    // for(int i=0;i<s1.size();i++){
    //     for(int j=0;j<s2.size();j++){
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << '\n';
    // }

    int ans = 0;
    for(int i=0;i<s2.size();i++){
        ans = max(ans, arr[s1.size()-1][i]);
    }
    cout << ans;
    
    return 0;
}