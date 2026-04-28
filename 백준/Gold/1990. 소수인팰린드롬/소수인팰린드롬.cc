#include <bits/stdc++.h>
using namespace std;

/*
소수를 구하는 데 걸리는 시간이 n log n log n 걸려서 먼저 소수를 구하는 건 답이 없음.
a~b의 팰린드롬 수를 구한 다음에 여기에 대해서 소수를 구해야 되는 거 같음.
1~1억 일때 팰린드롬을 n 안에 구할 수 있는가?
0 ~ 9 랑 11, 22 ,... 99에서 좌우로 같은 수를 추가하는 식으로 하려고 했으나 00, 000 같은 경우는 제대로 추가가 안될 거 같음.
string으로 추가한 뒤 stoi를 쓴다고 쳐도 stoi가 O(n)이라 안될 거 같음.

힌트를 받으니 팰린드롬 중 짝수 길이는 11의 배수라고 함. 
왜냐하면 11이든 1001 이든 100001 이든 전부 11의 배수이기 때문. 
따라서 짝수 길이를 가진 팰린 드롬은 11이라는 약수를 갖고 있기에 자기 자신인 11을 제외하고는 소수가 될 수 없음.
이로 인해 탐색 범위가 줄어드는 데 천만과 억 사이의 수는 짝수 길이(8) 이므로 팰린드롬 소수가 존재할 수 없기 때문임.
따라서 위에 했던 걱정은 안해도 되는 거
*/

bool is_prime[10000001];
int a,b;
vector<int> prime_num;

void input(){
    cin >> a >> b;
}

void check_prime(){
    for(int i=2;i<10000001;i++) is_prime[i] = true;
    for(int i=2;i<10000001;i++){
        if(!is_prime[i]) continue; // 이미 소수가 아니면 스킵
        if(a <= i && i <= b) prime_num.push_back(i);
        for(int j=i*2;j<10000001;j+=i){
            is_prime[j] = false;
        }
    }
}

bool is_palindrome(int num){
    string temp = to_string(num);
    int size = temp.size();
    for(int i=0;i<=size/2;i++){
        if(temp[i] != temp[size - 1 - i]) return false;
    }
    return true;
}

void solve(){
    check_prime();
    for(auto k : prime_num){
        if(is_palindrome(k)) cout << k << "\n";
    }
    cout << "-1";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    
    input();
    solve();

    return 0;
}