#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int a,b,c,d,e,f; cin>>a>>b>>c>>d>>e>>f;
    int x,y;
    y = (a*f-c*d)/(e*a-b*d);
    x = a!=0?(c-b*y)/a:(f-e*y)/d;
    cout << x<< " " << y;
    
    
    return 0;
}