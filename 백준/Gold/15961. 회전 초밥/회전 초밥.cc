#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,d,k,c; cin >> n >> d >> k >> c;
    vector<int> v(n); for(int i=0;i<n;i++) cin >> v[i];
    vector<int> cnt(d+1, 0);
    cnt[c]++;

    int ans;
    int score = 1;
    for(int i=0;i<k;i++){
        if(!cnt[v[i]]) score++;
        cnt[v[i]]++;
    }
    ans = score;

    for(int i=0;i<n;i++){
        cnt[v[i]]--;
        if(!cnt[v[i]]) score--;

        if(!cnt[v[(i+k)%n]]) score++; 
        cnt[v[(i+k)%n]]++;

        ans = max(ans, score);
    }
    cout << ans;

    return 0;
}