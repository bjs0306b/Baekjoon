#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a, b;
    cin >> a >> b;
    vector<int> v, v2;
    string s; cin >> s;
    string temp;
    for(auto k : s){
        if(k == ','){v.push_back(stoi(temp)); temp.clear();}
        else temp.push_back(k);
    }
    v.push_back(stoi(temp));
    for (int j = 0; j < b; j++)
    {
        if (j % 2)
        {
            v.clear();
            for (int i = 1; i < v2.size(); i++)
                v.push_back(v2[i] - v2[i - 1]);
        }
        else
        {  
            v2.clear();
            for (int i = 1; i < v.size(); i++)
                v2.push_back(v[i] - v[i - 1]);
        }
    }
    if(b%2){
        for(int i=0;i<v2.size()-1;i++) cout << v2[i] << ",";
        cout << v2[v2.size()-1];
    }
    else{
        for(int i=0;i<v.size()-1;i++) cout << v[i] << ",";
        cout << v[v.size()-1];
    }

    return 0;
}