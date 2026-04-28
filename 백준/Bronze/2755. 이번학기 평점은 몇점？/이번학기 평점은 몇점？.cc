#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <set>
#include <cmath>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int sum = 0;
    int s = 0;
    while (n--)
    {
        string a, c;
        int b;
        cin >> a >> b >> c;
        s+=b;
        switch (c[0])
        {
        case 'A':
        {
            if (c[1] == '+')
                sum += 1000 * 4.3 * b;
            else if (c[1] == '0')
                sum += 1000 * 4.0 * b;
            else
                sum += 1000 * 3.7 * b;
            break;
        }
        case 'B':
        {
            if (c[1] == '+')
                sum += 1000 * 3.3 * b;
            else if (c[1] == '0')
                sum += 1000 * 3.0 * b;
            else
                sum += 1000 * 2.7 * b;
            break;
        }
        case 'C':
        {
            if (c[1] == '+')
                sum += 1000 * 2.3 * b;
            else if (c[1] == '0')
                sum += 1000 * 2.0 * b;
            else
                sum += 1000 * 1.7 * b;
            break;
        }
        case 'D':
        {
            if (c[1] == '+')
                sum += 1000 * 1.3 * b;
            else if (c[1] == '0')
                sum += 1000 * 1.0 * b;
            else
                sum += 1000 * 0.7 * b;
            break;
        }
        case 'F':
            sum += 1000 * 0.0 * b;
            break;
        }
    }
    int ans = sum/s;
    int one = ans%10;
    if(one >= 5) ans = ans - one + 10;
    else ans =  ans - one;
    
    float r_ans = (float)ans / 1000;
    printf("%.2f", r_ans);
    
    

    return 0;
}
