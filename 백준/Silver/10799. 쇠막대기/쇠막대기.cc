#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <queue>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    string s; cin >> s; queue<char> q; int sum = 0;
    for(int i=0;i<s.size();i++){
        char c = s[i];
        if(c == '(') q.push('(');
        else if(c == ')'){
            if(s[i-1] == '('){
                q.pop();
                sum += q.size();
            }
            else{
                sum++;
                q.pop();
            }
        }
    }
    cout << sum;
    return 0;
}