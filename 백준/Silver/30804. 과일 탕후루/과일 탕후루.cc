#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    deque<pair<int, int>> deq;
    int cnt = 1;
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] == arr[i + 1])
            cnt++;
        else
        {
            deq.push_back({arr[i], cnt});
            cnt = 1;
        }
    }
    deq.push_back({arr[n - 1], cnt});

    //    for(int i=0;i<deq.size();i++){
    //         cout << deq[i].first << " " << deq[i].second << "\n";
    //     }
    queue<pair<int, int>> q;

    int ans = 0;
    int cnt2 = 0;
    for (int i = 0; i < deq.size(); i++)
    {
        if (q.size() > 1){
            if(q.front().first != deq[i].first) cnt2 -= q.front().second;
            else q.back().second += q.front().second;
            q.pop();
        }
        q.push(deq[i]);
        cnt2 += deq[i].second;

        ans = max(ans, cnt2);
    }
    cout << ans;

    return 0;
}