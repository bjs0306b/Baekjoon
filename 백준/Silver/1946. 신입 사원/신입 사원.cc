#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        vector<pair<int, int>> v;
        for(int i=0;i<num;i++){
            int a, b;
            cin >> a >> b;
            v.push_back({a, b});
        }
        sort(v.begin(), v.end());

        int cnt = 1;
        int tmp = 0;
        for(int i=1;i<num;i++){
            if(v[i].second < v[tmp].second){
                cnt++;
                tmp = i;
            }
        }
        cout << cnt << "\n";
    }

    return 0;
}