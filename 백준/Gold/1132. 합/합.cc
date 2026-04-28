#include <bits/stdc++.h>
using namespace std;

long long ans;

struct node{
    long long sum = 0;
    bool can_zero = true;

    bool operator<(const node& other){
        return sum > other.sum;
    }
};

bool visited[10];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<string> s(n); for(int i=0;i<n;i++) cin >> s[i];

    vector<node> v(10);
    for(int i=0;i<n;i++){
        v[s[i][0] - 'A'].can_zero = false;

        for(int j=0;j<s[i].size();j++){
            int num = s[i][j] - 'A';
            long long power = pow(10, s[i].size() - j - 1);
            v[num].sum += power;
        }
    }

    sort(v.begin(), v.end());

    for(int i=9;i>=0;i--){
        if(v[i].can_zero){
            visited[i] = true;
            break;
        }
    }

    long long temp = 9;
    for(int i=0;i<10;i++){
        if(!visited[i]){
            ans += temp * v[i].sum;
            temp--;
        }
    }

    cout << ans;

    return 0;
}