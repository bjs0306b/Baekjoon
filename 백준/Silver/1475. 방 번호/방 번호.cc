    #include <iostream>
#include <algorithm>
#include <string>
using namespace std;
    
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    string str; cin >> str;
    int arr[9]; for(int i=0;i<9;i++) arr[i]=0;
    for(string::iterator iter = str.begin(); iter != str.end(); iter++){
        int n = *iter - '0';
        if(n == 9) n = 6;
        arr[n]++;
    }   
    arr[6] = (arr[6]+1)/2;
    int max = *max_element(arr, arr+9);
    cout << max;    
    return 0;
}