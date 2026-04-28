#include <iostream>
#include <set>
using namespace std;


class num{
public:
    int a,b;
    num(){}
    num(int a, int b):a(a),b(b){}

     bool operator<(num other) const {
        if (a == other.a) {
            return b < other.b;
        }
        return a < other.a;
    }
};

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n;
    set<num> set1;


    for(int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        set1.insert(num(a,b));
    }

    for(auto x : set1){
        cout << x.a << " " << x.b << "\n";
    }

    return 0;
}