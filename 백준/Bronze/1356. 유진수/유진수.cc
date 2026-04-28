#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    int size = s.size();
    bool ans = false;
    if (size == 1)
        cout << "NO";
    else
    {
        
        for (int i = 0; i < size-1; i++)
        {
            long long mul1=1,mul2=1;
            for(int j=0;j<=i;j++){
                int num = s[j] - '0';
                mul1 *= num;
            }
            for(int j=i+1;j<size;j++){
                int num = s[j] - '0';
                mul2 *= num;
            }
            if(mul1 == mul2) ans = true;
        }

        if(ans) cout << "YES";
        else cout << "NO";
    }

    return 0;
}