#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    deque<int> q;
    int ans_1 = 0, ans_2 = 0;
    int n; cin >> n;
    for(int i=0;i<n;i++){
        int a; cin >> a;
        if(a == 1){
            int b; cin >> b;
            q.push_back(b);
            if(ans_1 < q.size()){
                ans_1 = q.size();
                ans_2 = q.back();
            }
            else if(ans_1 == q.size()) ans_2 = min(ans_2, q.back());
        }
        else if(a == 2){
            q.pop_front();
        }
    }
    cout << ans_1 << " " << ans_2;

    return 0;
}