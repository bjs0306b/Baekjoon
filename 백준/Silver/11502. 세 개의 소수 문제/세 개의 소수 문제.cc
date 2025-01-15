#include <bits/stdc++.h>
using namespace std;

vector<int> prime_nums;
bool prime_num[1000];
void SoE(){
    for(int i=2;i<1000;i++){
        if(!prime_num[i]){
            prime_nums.push_back(i);
            for(int j=i*2;j<1000;j+=i) prime_num[j] = true;
        }
    }
}

void print(int num){
    for(auto k : prime_nums){
        for(auto kk : prime_nums){
            for(auto kkk : prime_nums){
                if(k + kk + kkk == num){
                    cout << k << " " << kk << " " << kkk << "\n";
                    return;
                }
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
    SoE();
    while(n--){
        int num; cin >> num;
        print(num);
    }

    return 0;
}