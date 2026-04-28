#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> v;
bool visited[10];
int ans = 0;

void dfs(int depth, int score){
    if(depth == n-2){
        ans = max(ans, score);
        return;
    }
    else{
        for(int i=1;i<n-1;i++){
            if(!visited[i]){
                visited[i] = true;

                int left, right;
                for(int j=i;j>=0;j--) if(!visited[j]){left = j; break;}
                for(int j=i;j<n;j++) if(!visited[j]){right = j; break;}
                dfs(depth+1, score + v[left]*v[right]);
                visited[i] = false;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=0;i<n;i++){int num; cin >> num; v.push_back(num);}

    dfs(0, 0);

    cout << ans;

    return 0;
}