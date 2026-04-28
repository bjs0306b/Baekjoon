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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 1000; i < 10000; i++)
    {
        int cnt_10=0, cnt_12=0, cnt_16=0;
        string str_10 = to_string(i);
        for (auto k : str_10)
        {
            int temp = k - '0';
            cnt_10 += temp;
        }

        int temp = i;
        while (temp){
            cnt_12 += temp % 12;
            temp /= 12;
        }

        temp = i;
        while (temp){
            cnt_16 += temp % 16;
            temp /= 16;
        }

        if(cnt_10 == cnt_12 && cnt_12 == cnt_16) cout << i << '\n';
    }

    return 0;
}