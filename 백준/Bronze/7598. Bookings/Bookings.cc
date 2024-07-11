#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    string s; int cur_passenger;

    for(;;){
        cin >> s >> cur_passenger;
        if(s=="#" && cur_passenger == 0) break;

        char c; int num;
        
        for(;;){
            cin >> c >> num;
            if(c=='X' && num==0) break;

            if(c == 'B' && num + cur_passenger <= 68 ){
                cur_passenger += num;
            }
            else if(c == 'C' && cur_passenger - num >= 0)
                cur_passenger -= num;
        }

        cout << s << " " << cur_passenger << "\n";
    }
    
    return 0;
}   