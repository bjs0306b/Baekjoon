#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s1, s2;
    cin >> s1 >> s2;

    long long hash = 0;
    long long temp = 1;
    for (int i = 0; i < s2.size(); i++)
    {
        hash += temp * s2[i];
        temp *= 2;
    }
    // cout << hash <<'\n';
    if(s1.size() < s2.size()){cout << "FLURA"; return 0;}
    long long hash2 = 0;
    vector<char> vec;
    for (int i = 0; i < s1.size(); i++)
    {
        if (vec.size() < s2.size())
        {
            hash2 += pow(2, vec.size()) * s1[i];
            vec.push_back(s1[i]);
        }
        else
        {
            if (hash == hash2)
            {
                bool flag = true;

                for (int j = 0; j < s2.size(); j++)
                {
                    if (vec[vec.size() - s2.size() + j] != s2[j]){
                        flag = false;
                        break;
                    }
                }
                if (flag)
                {
                    for (int j = 0; j < s2.size(); j++)
                        vec.pop_back();
                    hash2 = 0;
                    int t = 0;
                    if (vec.size() < s2.size() - 1)
                    {
                        for (int j = 0; j < vec.size(); j++, t++)
                        {
                            hash2 += pow(2, t) * vec[j];
                        }
                    }
                    else
                    {
                        for (int j = vec.size() - s2.size() + 1; j < vec.size(); j++, t++)
                        {
                            hash2 += pow(2, t) * vec[j];
                        }
                    }
                    hash2 += pow(2, t) * s1[i];
                    vec.push_back(s1[i]);
                }
                else
                {
                    hash2 -= vec[vec.size() - s2.size()];
                    hash2 /= 2;
                    hash2 += pow(2, s2.size() - 1) * s1[i];
                    vec.push_back(s1[i]);
                }
            }
            else
            {
                hash2 -= vec[vec.size() - s2.size()];
                hash2 /= 2;
                hash2 += pow(2, s2.size() - 1) * s1[i];
                vec.push_back(s1[i]);
            }
        }
        // cout << hash2 << "\n";
    }
    if (hash == hash2)
        for (int j = 0; j < s2.size(); j++)
            vec.pop_back();

    if (vec.size())
    {
        for (int i = 0; i < vec.size(); i++)
        {
            cout << vec[i];
        }
    }
    else
        cout << "FRULA";

    return 0;
}