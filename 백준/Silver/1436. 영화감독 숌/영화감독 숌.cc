#include <iostream>
using namespace std;
#include <string>
bool _666ok(int n){
    string str = to_string(n);
    return str.find("666") != str.npos;
}
int main(){
    int n;
    int i = 0;
    int cnt = 0;
    cin >> n;
    while(n!=cnt){
        i++;
        if(_666ok(i)) cnt++;
    }
    cout << i;
}