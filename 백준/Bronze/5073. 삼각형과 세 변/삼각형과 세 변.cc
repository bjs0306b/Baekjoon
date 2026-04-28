#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int a,b,c;
    for(;;){
        cin >>a>>b>>c;
        if(a==0 && b==0 && c==0) break;
        int mx = max({a,b,c}); int sum = a+b+c;
        if(2*mx >= sum){cout << "Invalid\n"; continue;}
        if(a==b && b==c) cout << "Equilateral\n";
        else if (a==b || b==c || a==c) cout << "Isosceles\n";
        else cout << "Scalene\n";   
    }
    
    
    return 0;
}