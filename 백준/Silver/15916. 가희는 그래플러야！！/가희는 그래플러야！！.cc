#include <bits/stdc++.h>
using namespace std;

long long n, k;
long long current_pos = 0; // 1이면 y = kx 위, 2이면 아래.
vector<long long> v;

bool func(){
    for (long long i = 1; i <= n; i++)
    {
        if (v[i] > k * i) 
        {
            if (current_pos == 2) return true;
            current_pos = 1;
        }
        else if(v[i] < k * i){
            if(current_pos == 1) return true;
            current_pos = 2;
        }
        else return true;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    v.push_back(0);
    for (long long i = 0; i < n; i++)
    {
        long long num;
        cin >> num;
        v.push_back(num);
    }
    
    cin >> k;

    if(func()) cout << "T";
    else cout << "F";

    return 0;
}