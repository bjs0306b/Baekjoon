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

vector<int> v[5001];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        v[b].push_back(a);
    }
    for(int i=0;i<5001;i++) sort(v[i].begin(),v[i].end());
    int sum = 0;
    for(int i=0;i<5001;i++){
        if(v[i].size() == 0) continue;

        for(int j=0;j<v[i].size();j++){
            if(j==0) sum += v[i][1]-v[i][0];
            else if(j==v[i].size()-1) sum += v[i][j]-v[i][j-1];
            else sum += min(v[i][j]-v[i][j-1],v[i][j+1]-v[i][j]);
        }
    }
    cout << sum;

    return 0;
}