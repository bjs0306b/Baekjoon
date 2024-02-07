#include <iostream>
#include <algorithm>
#include <string>
#include <deque>
using namespace std;


// int main(){
//     ios_base::sync_with_stdio(0);cin.tie(0);
//     string s; cin >> s;
//     deque<int> v,v2;
//     int arr[8] = {3,0,3,0,0,0,0,2};
//     for(int i=0;i<s.size();i++){
//         int num; num = s[i] - '0';
//         v.push_back(num);
//     }
//     for(;;){
//         v2 = v;
//         for(int i=0;i<8;i++){
//             v[v.size()-1-i] -= arr[i];
//         }
//         for(int i=v.size()-1;i>0;i--){
//             if(v[i] < 0){v[i-1]--; v[i]+=10;}
//         }
//         if(v[0] < 0) break;
//     }
//     for(;;){
//         if(v2.front() == 0)
//             v2.pop_front();
//         else break;
//     }
//     if(v2.size() == 0) cout << "0";
//     else for(auto a: v2) cout << a;


//     return 0;
// }

// 위에꺼는 시간초과 남. 제출은 파이썬으로 하긴 했는데 cpp 답지를 찾아봄.
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    string s; cin >> s;
    int result = 0;
    for(int i=0;i<s.size();i++){
        int digit = s[i] - '0';

        result = ((result*10)%20000303+digit)%20000303;
    }
    cout << result;
    
    
    return 0;
}

