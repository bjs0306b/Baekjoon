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
    multiset<float> st;
    int n; cin >> n;
    float end;
    for(int i=0;i<7;i++){
        float f; cin >> f;
        st.insert(f);
    }
    end = *(--st.end());
    for(int i=0;i<n-7;i++){
        float f; cin >> f;
        if(end > f){
            st.erase(--st.end());
            st.insert(f);
            end = *(--st.end());
        }
    }
    for(auto k : st) printf("%.3f\n",k);
   
    
    return 0;
}