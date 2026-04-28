#include <bits/stdc++.h>
using namespace std;



bool is_similar(string a, string b){
    string s1 = "", s2 = "";
    vector<int> visited1(26, 0), visited2(26, 0);

    int cnt1 = 1;
    for(int i=0;i<a.size();i++){
        int num = a[i] - 'a';
        if(!visited1[num]){
            visited1[num] = cnt1++;    
        }
        s1 += (visited1[num] + '0');
    }
    int cnt2 = 1;
    for(int i=0;i<b.size();i++){
        int num = b[i] - 'a';
        if(!visited2[num]){
            visited2[num] = cnt2++;    
        }
        s2 += (visited2[num] + '0');
    }
    if(s1 == s2) return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<string> v(n); for(int i=0;i<n;i++) cin >> v[i];

    int ans = 0;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(is_similar(v[i], v[j])){
                ans++;
            }
        }
    }
    cout << ans;

    return 0;
}