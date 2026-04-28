#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t; cin >> t;
    int cost = 0;
    for(int i=0;i<t;i++){
        string s; int n;
        cin >> s >> n;
        int hour = stoi(s.substr(0,3));
        int minute = stoi(s.substr(3,5));

        if(hour == 6 && minute + n > 60)
            cost += ((60 - minute) * 5 + (minute + n - 60) * 10);
        else if(hour == 18 && minute + n > 60)
            cost += ((60 - minute) * 10 + (minute + n - 60) * 5);
        else if(7 <= hour && hour < 19) cost += n * 10;
        else cost += n * 5;
    }

    cout << cost;
    
    return 0;
}