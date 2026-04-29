#include <bits/stdc++.h>
using namespace std;

long long solve(){
    long long n, m;
    cin >> n >> m;
    priority_queue<long long> pq1; // 최대힙
    priority_queue<long long, vector<long long>, greater<long long>> pq2; // 최소힙
    long long ans = 0;
    for(long long i=0;i<n;i++){
        int cnt1 = 0, cnt2 = 0;
        for(long long j=0;j<2;j++){
            long long num; cin >> num;
            if(num < m){
                pq1.push(num);
                cnt1++;
            }
            else{
                pq2.push(num);
                cnt2++;
            }
        }

        if(cnt1 > cnt2){
            pq2.push(m);
            m = pq1.top();
            pq1.pop();
        }
        else if(cnt1 < cnt2){
            pq1.push(m);
            m = pq2.top();
            pq2.pop();
        }

        ans = (ans + m) % 20171109;
    }
    return ans;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    long long t; cin >> t;
    for(long long i=1;i<=t;i++){
        cout << "#" << i << " " << solve() << "\n";
    }
    return 0;
}