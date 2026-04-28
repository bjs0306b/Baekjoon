#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    stack<int> st;
    for(int i=0;i<n;i++){
        char c; cin >> c; st.push(c-'A'+1);
    }
    while(!(st.size() == 1)){
        int a = st.top(); st.pop();
        int b = st.top(); st.pop();
        if(a == b) st.push(a);
        else if(a*b == 3 || a*b == 140) st.push(1);
        else if(a*b == 7) st.push(3);
        else if(a*b == 20 || a*b == 60) st.push(7);
        else if(a*b == 21) st.push(20);
    }
    char ans = st.top() + 'A' - 1;
    cout << ans;
    
    return 0;
}