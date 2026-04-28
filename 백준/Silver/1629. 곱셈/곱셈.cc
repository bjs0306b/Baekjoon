#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <set>
#include <cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    long long a,b,c,ans=1; cin >> a>>b>>c;
    while(b){
        if(b%2) ans = (ans*a)%c;
        a = (a*a)%c; b/=2;
    }
    cout << ans;
    return 0;
}
//답지 봄


// 실패작.. 메모리 초과, 시간 초과
// int main(){
//     ios_base::sync_with_stdio(0);cin.tie(0);
//     long long a,b,c; cin >> a >> b >> c;
//     vector<long long> v, v2; set<long long> s;
//     long long ans = a%c;
//     long long pos;
//     v.push_back(ans);
//     s.insert(ans);
//     for(int i=1;i<b;i++){
//         ans = (ans*a)%c;
//         if(s.find(ans) != s.end()){
//             auto iter = find(v.begin(), v.end(), ans);
//             pos = iter - v.begin();
//             for(;iter!=v.end();iter++){
//                 v2.push_back(*iter);
//             }
//             ans = v2[(b-pos-1)%v2.size()];
//             break;
//         }
//         s.insert(ans);
//         v.push_back(ans);
//     }
//     cout << ans;
    
    


//     return 0;
// }   