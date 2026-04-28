#include<bits/stdc++.h>
using namespace std;

struct jewel {
    int a, b;
    bool operator<(const jewel& other) const {
        if(b == other.b) a > other.a;
        return b < other.b;
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, k; cin >> n >> k;
    priority_queue<jewel> pq;

    while (n--) {
        int a, b; cin >> a >> b;
        pq.push({a, b});
    }

    multiset<int> bags; 

    while (k--) {
        int c; cin >> c;
        bags.insert(c);
    }

    long long ans = 0;  

    // Process jewels
    while (!pq.empty()) {
        jewel j = pq.top();
        pq.pop();

        auto iter = bags.lower_bound(j.a);
        if (iter == bags.end()) continue;  

        ans += j.b; 
        bags.erase(iter);  
    }
    
    cout << ans;

    return 0;
}
