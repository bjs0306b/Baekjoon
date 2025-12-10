#include <bits/stdc++.h>
using namespace std;

int n, m, A[100][10000], sort_index_A[100][10000];
bool visited[100];
int ans = 0;

void input()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> A[i][j];
        }
    }
}

void sort_and_index_check(){
    
    for(int i=0;i<n;i++){
        vector<int> v(m);
        for(int j=0;j<m;j++){
            v[j] = A[i][j];
        }
        vector<int> temp = v;
        sort(temp.begin(), temp.end());
        temp.erase(unique(temp.begin(), temp.end()), temp.end());
        
        for(int j=0;j<m;j++){
            int idx = lower_bound(temp.begin(), temp.end(), v[j]) - temp.begin();
            sort_index_A[i][j] = idx;
        }
    }
}

bool compare_set(int a, int b){
    for(int i=0;i<m;i++){
        if(sort_index_A[a][i] != sort_index_A[b][i]) return false;
    }
    return true;
}

void set_cnt(){
    for(int i=0;i<n;i++){
        set<int> s;
        if(visited[i]) continue;
        for(int j=0;j<n;j++){
            if(i == j || visited[j]) continue;

            if(compare_set(i,j)){
                s.insert(i);
                s.insert(j);
            }
        }
        int size = s.size();
        ans += size*(size-1)/2;
        for(auto k : s) visited[k] = true;
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    input();
    sort_and_index_check();
    set_cnt();
    cout << ans;

    return 0;
}