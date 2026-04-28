#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
   int a,b; cin >>a>>b;
   if(b < 3) cout << "NEWBIE!";
   else if(b<=a) cout << "OLDBIE!";
   else cout << "TLE!";
    
    return 0;
}