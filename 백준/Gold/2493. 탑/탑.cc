#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;


    stack<pair<int,int>> s;
    for(int i=1;i<=n;i++){
        int num; cin >> num;
        while(!s.empty()){
            if(s.top().first > num){
                cout << s.top().second <<" ";
                break;
            }
            s.pop();
        }
        if(s.empty()) cout << "0 ";

        s.push({num, i});
    }

    return 0;
}