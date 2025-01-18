#include <bits/stdc++.h>
using namespace std;
int a,b; 
unordered_map<int, bool> um;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> a >> b;

    if(a == b){
        cout << 0;
        return 0;
    }
    if(b == 0){
        cout << "-";
        return 0;
    }

    queue<pair<int, string>> q;
    um[a] = true;
    q.push({a, ""});

    while(!q.empty()){       
        auto temp = q.front();
        q.pop();
        if(temp.first == b){
            cout << temp.second;
            return 0;
        }
        
        if(!um[temp.first * temp.first] &&temp.first <= 33333){
            q.push({temp.first*temp.first, temp.second+'*'});
            um[temp.first*temp.first] = true;
        }
        if(!um[2*temp.first] && temp.first*2 <= 1000000000){
            q.push({temp.first*2, temp.second+'+'});
            um[2*temp.first] = true;
        }
        if(!um[1]){
            q.push({1, temp.second+'/'});
            um[1] = true;
        }  
    }

    cout << -1;


    return 0;
}