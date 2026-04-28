#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

class coordinate{
public:
    int x,y;
    coordinate(){}
    coordinate(int a, int b):x(a),y(b){}

    bool operator<(coordinate other) const{
        if(y == other.y) return x < other.x;
        return y < other.y;
    }
};
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    set<coordinate> s;
    cin >> n;

    for(int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        s.insert(coordinate(a,b));
    }
    for(auto x : s) cout << x.x << " " << x.y << "\n";

    return 0;
}   