#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    
    for(int i=0;i<n;i++){
        int a,b,c; cin >> a >> b >> c;

        int line = 0;
        int columns = 0;

        for(int j=0;j<a;j++){
            for(int k=0;k<b-1;k++){
                columns++;
                if(columns == c){
                    line++; columns = 0;
                }
            }
            line++;
            columns = (columns + 1)%c;
        }

        cout << "Case #" << i+1 << ": " << line << "\n";
    }
    
    return 0;
}