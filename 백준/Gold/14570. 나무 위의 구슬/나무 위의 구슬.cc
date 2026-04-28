#include <bits/stdc++.h>
using namespace std;

long long n,k;
vector<pair<long long,long long>> v;

void input()
{
    cin >> n;
    v.resize(n + 1);
    for (long long i = 1; i <= n; i++)
    {
        long long a, b;
        cin >> a >> b;
        v[i] = {a,b};
    }
    cin >> k;
}

void dfs(long long num, long long idx){
    // 자식 없음 -> 멈추고 출력
    if(v[idx].first == -1 && v[idx].second == -1){
        cout << idx;
        return;
    }
    else if(v[idx].first == -1 && v[idx].second != -1){
        dfs(num, v[idx].second);
    }
    else if(v[idx].first != -1 && v[idx].second == -1){
        dfs(num, v[idx].first);
    }
    else{
        if(num % 2) dfs(num/2+1, v[idx].first);
        else dfs(num/2, v[idx].second);
    }
}

void solve()
{
    dfs(k, 1);
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    input();
    solve();

    return 0;
}