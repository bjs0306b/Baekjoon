#include <bits/stdc++.h>
using namespace std;

vector<bool> prime_num(100000001, 1);

void Sieve_of_Eratosthenes()
{
    prime_num[1] = 0;
    for (int i = 2; i < 100000001; i++)
    {
        if (prime_num[i])
        {
            for (int j = 2 * i; j < 100000001; j += i)
            {
                prime_num[j] = 0;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    Sieve_of_Eratosthenes();
    while(n--){
        int m; cin >> m;
        vector<int> v(m); for(int i=0;i<m;i++) cin >> v[i];
        vector<int> sum(m+1, 0); 
        for(int i=0;i<m;i++) sum[i+1] = sum[i] + v[i];
        bool flag = true;
        for(int i=2;i<=m;i++){
            for(int j=0;j<=m-i;j++){
                if(prime_num[sum[j+i] - sum[j]]){
                    flag = false;
                    cout << "Shortest primed subsequence is length " << i << ": ";
                    for(int k=j;k<j+i;k++) cout << v[k] << " ";
                    cout << "\n";
                    break;
                }
            }
            if(!flag) break;
        }
        if(flag) cout << "This sequence is anti-primed.\n";

    }

    return 0;
}