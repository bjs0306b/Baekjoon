#include <vector>
#include <string>
#include <iostream>
using namespace std;

int solution(vector<string> arr)
{
    vector<int> num;
    vector<string> oper;
    for(int i=0;i<arr.size();i++){
        string temp = arr[i];
        if(i % 2) oper.push_back(temp); // 기호
        else num.push_back(stoi(temp)); // 숫자
    }
    int n = num.size();
    int mx[n][n], mn[n][n]; for(int i=0;i<n;i++) for(int j=0;j<n;j++){mx[i][j] = INT32_MIN; mn[i][j] = INT32_MAX;}
    
    for(int i=0;i<n;i++) mx[i][i] = mn[i][i] = num[i];
    for(int i=0;i<n-1;i++){
        if(oper[i] == "-") mx[i][i+1] = mn[i][i+1] = num[i] - num[i+1];
        else mx[i][i+1] = mn[i][i+1] = num[i+1] + num[i];
    }
    
    for(int l=3;l<=n;l++){
        for(int s=0;s<n-l+1;s++){
            int e = s + l - 1;
            for(int i=s;i<e;i++){

                if(oper[i] == "-"){
                    mn[s][e] = min(mn[s][e], mn[s][i] - mx[i+1][e]);
                    mx[s][e] = max(mx[s][e], mx[s][i] - mn[i+1][e]);
                }
                else{
                    mn[s][e] = min(mn[s][e], mn[s][i] + mn[i+1][e]);
                    mx[s][e] = max(mx[s][e], mx[s][i] + mx[i+1][e]);
                }
                
            }
        }
    }
    
    return mx[0][n-1];
}