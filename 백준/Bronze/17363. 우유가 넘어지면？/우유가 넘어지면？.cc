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
    int a,b; cin >> a >> b;
    char arr[a][b]; for(int i = 0; i < a; i++) for(int j = 0; j < b; j++) cin >> arr[i][j];

    for(int i = b-1; i >=0; i--){
        for(int j = 0; j < a; j++){
            char temp = arr[j][i];
            if(temp == '-') cout << '|';
            else if(temp == '|') cout << '-';
            else if(temp == '/') cout << '\\';
            else if(temp == '\\') cout << '/';
            else if(temp == '^') cout << '<';
            else if(temp == '<') cout << 'v';
            else if(temp == 'v') cout << '>';
            else if(temp == '>') cout << '^';
            else cout << temp; 
        }
        cout << '\n';
    }
    
    
    return 0;
}