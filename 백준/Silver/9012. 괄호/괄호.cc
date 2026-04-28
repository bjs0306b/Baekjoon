#include <iostream>
#include <string>
using namespace std;
void check(char* c){
    int cnt = 0;
    int num = 0;
    while(c[num]){
        if(c[num] == '(') cnt++;
        else if(c[num] == ')') cnt--;
        num++;
        if(cnt < 0){
            cout << "NO" << "\n";
            return;
        }
    }

    if(cnt == 0) cout << "YES" << "\n";
    else cout << "NO" << "\n";
    return;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        char str[51];
        cin >> str;
        check(str);
    }
    return 0;
}