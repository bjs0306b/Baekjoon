#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n;
    vector<char> v;
    int arr[26]; for(int i=0;i<26;i++) arr[i] = 0;
    while(n--){
        string s; cin >> s; int num = s[0] - 'a';
        arr[num]++;
    }
    for(int i=0;i<26;i++){
        if(arr[i] > 4) v.push_back('a'+i);
    }
    if(v.size() == 0) cout << "PREDAJA";
    else for(auto a : v) cout << a;
    
    return 0;
}