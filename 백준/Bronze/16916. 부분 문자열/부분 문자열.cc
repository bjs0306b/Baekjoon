#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <deque>
#include <set>
#include <cmath>
#include <string.h>
using namespace std;

#define MAX 1000001
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    char a[MAX],b[MAX]; scanf("%s %s", a, b);
    char* ans = strstr(a,b);
    if(ans == NULL) cout << 0;
    else cout << 1;
    
    return 0;
}

// 라빈-카프 알고리즘 (Rabin-Karp)인데 string 길이가 너무 길어지면 overflow를 막을 수가 없나보다..
// int main(){
//     ios_base::sync_with_stdio(0);cin.tie(0);
//     string a,b; cin >> a >> b;
//     int hash_b =0;
//     int size_b = b.size();
//     for(int i = size_b-1; i>=0; i--){
//         hash_b += pow(size_b, i)*((int)b[size_b-1-i]);
//         hash_b %= 65536;
//     }
//     int hash_a = 0;
//     int size_a = a.size();
//     for(int i = size_b-1; i>=0; i--){
//         hash_a += pow(size_b, i)*((int)a[size_b-1-i]);
//         hash_a %= 65536;
//     }
//     if(hash_a == hash_b){cout << 1; return 0;}

//     for(int i=size_b;i<size_a;i++){
//         hash_a = size_b*(hash_a - (int)a[i-size_b]*pow(size_b, size_b-1)) + (int)a[i];
//         if(hash_a == hash_b) {cout << 1; return 0;}
//     }
//     cout << 0;
    
//     return 0;
// }