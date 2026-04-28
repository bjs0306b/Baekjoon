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

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    string arr[14] = {"baby","sukhwan","tururu","turu","very","cute","tururu","turu","in","bed","tururu","turu","baby","sukhwan"};
    
    int rep = n / 14;
    int idx = (n-1) % 14;

    if(idx%4 == 2){
        if(rep > 2)
        {
            cout << "tu+ru*";
            cout << rep + 2;
        }
        else{
            cout << "tururu";
            for(int i=0;i<rep;i++) cout << "ru";
        }
    }
    else if(idx%4 == 3){
        if(rep > 3)
        {
            cout << "tu+ru*";
            cout << rep + 1;
        }
        else{
            cout << "turu";
            for(int i=0;i<rep;i++) cout << "ru";
        }
    }
    else cout << arr[idx];
    return 0;
}