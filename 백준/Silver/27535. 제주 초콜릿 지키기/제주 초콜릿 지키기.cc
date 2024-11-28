#include <bits/stdc++.h>
using namespace std;

string formation(int num, int n){
    if(num == 0) return "0";
    string temp = "";
    while(num){
        char c = (num % n) + '0';
        temp.push_back(c);
        num /= n;
    }
    reverse(temp.begin(), temp.end());
    // int ret = stoi(temp);
    return temp;
}

bool cmp(pair<int, char> a, pair<int, char> b)
{
    if (a.first == b.first)
        return a.second < b.second;
    return a.first > b.first;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int sum = 0;
    int arr[5];
    for (int i = 0; i < 5; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    int n;
    cin >> n;
    int jinbub = sum % 10;
    char choconame[5] = {'H', 'T', 'C', 'K', 'G'};
    while (n--)
    {
        for (int i = 0; i < 5; i++)
        {
            int num;
            cin >> num;
            arr[i] -= num;
            sum -= num;
        }
        if (jinbub < 2)
            cout << sum << "7H\n";
        else
            cout << formation(sum, jinbub) << "7H\n";
            
        jinbub = sum % 10;

        vector<pair<int, char>> v;
        for (int i = 0; i < 5; i++)
        {
            v.push_back({arr[i], choconame[i]});
        }
        sort(v.begin(), v.end(), cmp);

        if (sum == 0)
            cout << "NULL";
        else
        {
            for (int i = 0; i < v.size(); i++)
            {
                if (v[i].first > 0)
                    cout << v[i].second;
            }
        }

        cout << "\n";
    }

    return 0;
}