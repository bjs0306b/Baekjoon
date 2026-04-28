#include <bits/stdc++.h>
using namespace std;
int cnt[100001];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    int ans = 0;
    deque<int> deq;
    for(int i=0;i<n;i++){
        deq.push_back(arr[i]);
        if(++cnt[arr[i]] > k){
            while(deq.front() != arr[i]){
                cnt[deq.front()]--;
                deq.pop_front();
            }
            cnt[deq.front()]--;
            deq.pop_front();
        } 
        int size = deq.size();
        ans = max(ans, size);
    }
    cout << ans;

    return 0;
}