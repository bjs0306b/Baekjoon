#include <bits/stdc++.h>
using namespace std;

int l,c;
vector<char> v;
bool visited[15];
char arr[15];
set<string> ss;
void dfs(int n, int m){
    if(l == n){
        int cnt1 = 0 , cnt2 = 0; // cnt1 - 자음, cnt2 - 모음.
        for(int i=0;i<l;i++){
            if(arr[i] == 'a' || arr[i] == 'e' ||arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u') cnt2++;
            else cnt1++;
        }
        if(cnt1 > 1 && cnt2 > 0){
            string s = "";
            for(int i=0;i<l;i++) s += arr[i];
            ss.insert(s);
        }
    }
    else{
        for(int i=m;i<v.size();i++){
            if(!visited[i]){
                arr[n] = v[i];
                visited[i] = true;

                dfs(n+1, i+1);

                arr[n] = ' ';
                visited[i] = false;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> l >> c;
    for(int i=0;i<c;i++){
        char c; cin >> c;
        v.push_back(c);
    }
    sort(v.begin(), v.end());

    dfs(0,0);

    for(auto k : ss) cout << k << "\n";
    return 0;
}