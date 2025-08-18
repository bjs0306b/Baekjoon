#include <bits/stdc++.h>
using namespace std;

vector<bool> is_prime(1000001, true);
vector<int> prime_num;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    is_prime[1] = false;
    for(int i=2;i<1000001;i++){
        if(is_prime[i]){
            prime_num.push_back(i);
            for(int j=i*2;j<1000001;j+=i){
                is_prime[j] = false;
            }
        }
    }

    int n; 
    for(;;){
        cin >> n; if(!n) break;
        for(int i=1;i<prime_num.size();i++){
            int num = n - prime_num[i];
            if(is_prime[num]){
                cout << n << " = " << prime_num[i] << " + " << num << "\n"; 
                break;  
            }
        }
    }
    
    return 0;
}