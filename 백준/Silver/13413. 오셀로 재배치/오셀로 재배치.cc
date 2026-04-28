#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    while(n--){
        int num; cin >> num;
        string s1, s2; cin >> s1 >> s2;

        int dif=0, nm=0;

        int b1=0,b2=0;
        for(int i=0;i<num;i++){
            if(s1[i] == 'B') b1++;
            if(s2[i] == 'B') b2++;

            if(s1[i] != s2[i]) nm++;
        }

        dif = abs(b1-b2);

        cout << (dif + nm)/2 << "\n";
    }
    
    return 0;
}