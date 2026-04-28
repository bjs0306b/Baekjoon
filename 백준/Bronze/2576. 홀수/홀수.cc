#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    vector<int> v;
    int sum = 0;
    for(int i=0;i<7;i++){
        int num; cin >> num;
        if(num % 2 == 1){ sum += num; v.push_back(num);}
    }
    if(v.size()) cout << sum << "\n" << *min_element(v.begin(), v.end());
    else cout << -1;
    
    return 0;
}