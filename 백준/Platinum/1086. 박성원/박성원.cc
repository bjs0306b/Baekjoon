#include <bits/stdc++.h>
using namespace std;

int n,m; 
vector<string> v; 
long long dp[32768][100];
int ten_pow_m_remain[51];
int get_remain_string_v[15];

long long gcd(long long a, long long b){
    if(a % b) return gcd(b, a%b);
    return b;
}

int get_remain_string_int(string s, int num){
    int ret = 0;
    for(int i=0;i<s.size();i++){
        ret *= 10;
        ret += (s[i] - '0');
        ret %= num;
    }
    return ret;
}

void input(){
    cin >> n;
    v.resize(n);
    for(int i=0;i<n;i++) cin >> v[i];
    cin >> m;

    ten_pow_m_remain[0] = 1;
    for(int i=1;i<51;i++){
        ten_pow_m_remain[i] = ten_pow_m_remain[i-1] * 10 % m;
    }
    for(int i=0;i<n;i++){
        get_remain_string_v[i] = get_remain_string_int(v[i], m);
    }
}

void solve(){
    dp[0][0] = 1;

    for(int i=0;i<(1<<n);i++){
        for(int j=0;j<n;j++){
            int temp = 1 << j;

            if((i & temp) != 0) continue; // 이미 방문한 곳임.

            int next = i | temp;

            for(int k=0;k<m;k++){
                int nx_k = k * ten_pow_m_remain[v[j].size()] % m + get_remain_string_v[j];
                nx_k %= m;
                dp[next][nx_k] += dp[i][k];
            }
        }
    }

    long long all_case = 1; // 전체 경우의 수(nPn) 
    for(int i=1;i<=n;i++){
        all_case *= i;
    }
    
    long long correct_case = dp[(1<<n)-1][0];

    if(correct_case == 0){
        cout << "0/1";
        return;
    }
    long long gcd_value = gcd(all_case, correct_case);
    correct_case /= gcd_value;
    all_case /= gcd_value;


    cout << correct_case << "/" << all_case;
    
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    input();
    solve();

    return 0;
}