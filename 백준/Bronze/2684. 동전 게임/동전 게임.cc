#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;
int arr[8];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    while(n--){
        string s; cin >> s;
        string temp;
        for(int i=0;i<38;i++){
            temp = s.substr(i,3);
            if(temp == "TTT") arr[0]++;
            else if(temp == "TTH") arr[1]++;
            else if(temp == "THT") arr[2]++;
            else if(temp == "THH") arr[3]++;
            else if(temp == "HTT") arr[4]++;
            else if(temp == "HTH") arr[5]++;
            else if(temp == "HHT") arr[6]++;
            else if(temp == "HHH") arr[7]++;
        }
        

        for(int i=0;i<8;i++) cout << arr[i] << " ";
        cout << "\n";
        memset(arr,0,sizeof(arr));
    }
    
    return 0;
}