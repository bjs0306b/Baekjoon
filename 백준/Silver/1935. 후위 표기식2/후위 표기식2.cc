#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <set>
#include <cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    double arr[n];
    string s; cin >> s;
    for(int i=0;i<n;i++){int num; cin >> num; arr[i] = num;}
    vector<double> v;
    for(auto k : s){
        if(k=='+'){
            double num1 = v.back(); v.pop_back();
            double num2 = v.back(); v.pop_back();
            v.push_back(num1+num2);
        }
        else if(k=='-'){
            double num1 = v.back(); v.pop_back();
            double num2 = v.back(); v.pop_back();
            v.push_back(num2-num1);
        }
        else if(k=='*'){
            double num1 = v.back(); v.pop_back();
            double num2 = v.back(); v.pop_back();
            v.push_back(num1*num2);
        }
        else if(k=='/'){
            double num1 = v.back(); v.pop_back();
            double num2 = v.back(); v.pop_back();
            v.push_back(num2/num1);
        }
        else{
            int num = k -'A';
            v.push_back(arr[num]);
        }
    }
    double ans = v.back();
    printf("%.2f", ans);
    return 0;
}