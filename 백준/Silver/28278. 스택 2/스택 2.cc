#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <stack>
#include <cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n;
    stack<int> st;
    for(int i=0;i<n;i++){
        int num; cin >> num;
        if(num == 1){
            int a; cin >> a;
            st.push(a);
        }
        else if(num == 2){
            if(!st.empty()){
                cout << st.top() << "\n";
                st.pop();
            }
            else cout << -1 << "\n";
        }
        else if(num == 3){
            cout << st.size() << "\n";
        }
        else if(num == 4){
            if(st.empty()) cout << 1 << "\n";
            else cout << 0 << "\n";
        }
        else if(num == 5){
            if(!st.empty()) cout << st.top() << "\n";
            else cout << -1 << "\n";
        }
    }
    
    return 0;
}