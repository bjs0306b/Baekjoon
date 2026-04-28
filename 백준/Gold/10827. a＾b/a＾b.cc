#include <bits/stdc++.h>
using namespace std;

string add(string a, string b)
{
    if (a.size() < b.size())
        swap(a, b); // a가 큼.

    int i = a.size() - 1;
    bool flag = false;
    for (int j = b.size() - 1; j >= 0; j--, i--)
    {
        int num = (a[i] - '0') + (b[j] - '0');
        if (flag)
        {
            num++;
            flag = false;
        }
        if (num > 9)
        {
            flag = true;
            num -= 10;
        }
        a[i] = num + '0';
    }
    for (; i >= 0; i--)
    {
        int num = a[i] - '0';
        if (flag)
        {
            num++;
            flag = false;
        }
        if (num > 9)
        {
            flag = true;
            num -= 10;
        }
        a[i] = num + '0';
    }

    if (flag)
        return "1" + a;
    return a;
}

string multiply(string a, string b)
{
    string ret = "0";

    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < b.size(); j++)
        {
            int num = (a[i] - '0') * (b[j] - '0');
            if (num == 0)
                continue;
            string temp = to_string(num);

            temp += string(a.size() + b.size() - i - j - 2, '0');

            ret = add(ret, temp);
        }
    }

    return ret;
}

string func(string s, int num){
    if(num == 1) return s;

    return multiply(func(s, num/2), func(s,num-num/2));
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    string s; cin >> s;
    int n; cin >> n;

    int sosu_size = s.end() - find(s.begin(), s.end(), '.') - 1;
    string temp = "", temp2 = "";

    for(int i=0;i<s.size();i++){
        if(s[i] == '.') continue;   
        temp2 += s[i];
    }

    int idx = 0;
    for(;idx<temp2.size();idx++){
        if(temp2[idx] != '0') break;
    }

    for(;idx<temp2.size();idx++){
        temp += temp2[idx];
    }

    string ans = "1";

    ans = func(temp, n);

    int ans_size = ans.size();

    if(ans_size - sosu_size*n > 0){
        for(int i=0;i<ans_size-sosu_size*n;i++)
            cout << ans[i];
        cout << ".";
        for(int i=ans_size-sosu_size*n;i<ans_size;i++)
            cout << ans[i];
    }
    else{
        cout << "0.";
        for(int i=0;i<sosu_size*n-ans_size;i++) cout << "0";
        cout << ans;
    }

    return 0;
}