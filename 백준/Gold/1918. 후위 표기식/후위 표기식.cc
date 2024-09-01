#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    string s; cin >> s;
    stack<char> st;
    for(auto k : s){
        if(k >= 'A' && k <= 'Z'){
            cout << k;
        }
        else{
            if(st.empty()){
                st.push(k);
            }
            else{
                if(k == ')'){
                    st.push(')');
                    for(;;){
                        st.pop();
                        if(st.top() == '('){
                            st.pop(); break;
                        }
                        cout << st.top();   
                    }
                }
                else if(k == '*' || k == '/'){
                    while(!st.empty() && (st.top() == '/' || st.top() == '*')){
                        cout << st.top(); st.pop();
                    }
                    st.push(k);
                }
                else if(k == '+' || k == '-'){
                    while(!st.empty() && st.top() != '('){
                        cout << st.top(); st.pop();
                    }
                    st.push(k);
                }
                else{  // '(' 
                    st.push(k);
                }
            }
        }
    }
    while(!st.empty()){
        cout << st.top();
        st.pop();
    }
    
    
    return 0;
}