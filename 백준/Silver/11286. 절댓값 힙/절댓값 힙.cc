#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <deque>
#include <set>
#include <cmath>
#include <queue>
using namespace std;

bool check(int a, int b)
{
    if (abs(a) == abs(b))
        return a > b;
    return abs(a) > abs(b);
}

struct cmp
{
    bool operator()(const int& a, const int& b)
    {
        if (abs(a) == abs(b))
            return a > b;
        return abs(a) > abs(b);
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    priority_queue<int, vector<int>, cmp> pq;
    while(n--){
        int num; cin >> num;
        if(num==0){
            if(pq.empty()) cout << 0 << "\n";
            else{
                cout << pq.top() << "\n";
                pq.pop();
            }
        }
        else{
            pq.push(num);
        }
    }

        return 0;
}