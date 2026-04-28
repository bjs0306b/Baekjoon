#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    string str;
    cin  >> str;
    string::iterator iter;
    int arr[26]; for(int i=0;i<26;i++) arr[i]=0;
    for(iter = str.begin(); iter != str.end(); iter++){
        int index = *iter - 'a';
        arr[index]++;
    }
    for(int i=0;i<26;i++) cout << arr[i] << " ";
    return 0;
}