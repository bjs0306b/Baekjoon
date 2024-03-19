#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <deque>
#include <set>
#include <cmath>
using namespace std;
int arr[100];
class student{
public:
    int a,b,c;

    student(){}
    student(int aa, int bb, int cc):a(aa),b(bb),c(cc){}

    bool operator <(const student &s) const{
        return c > s.c;
    }
};
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    vector<student> v;
    
    while(n--){
        int a,b,c; cin >> a >> b >> c;
        v.push_back(student(a,b,c));
    }
    sort(v.begin(),v.end());
    for(int i=0, cnt=0; cnt < 3;i++){
        if(arr[v[i].a] < 2){
            arr[v[i].a]++;
            cout << v[i].a << " " << v[i].b << "\n";
            cnt++;
        }
        
    }
    
    return 0;
}
