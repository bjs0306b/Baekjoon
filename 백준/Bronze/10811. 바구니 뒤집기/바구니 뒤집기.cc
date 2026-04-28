#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);   
    cin.tie(0);
    int a, b;
    cin >> a >> b;
    vector<int> v;
    for(int i=0;i<a;i++) v.push_back(i+1);
    for(int i=0;i<b;i++){
        int c,d; cin >>c>>d;
        reverse(v.begin()+c-1, v.begin()+d);  
    }
    for(vector<int>::iterator iter = v.begin(); iter != v.end(); iter++) cout << *iter <<" ";
    return 0;
}