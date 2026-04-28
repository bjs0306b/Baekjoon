#include <bits/stdc++.h>
using namespace std;

vector<bool> arr(118, 1);
vector<int> prime_num;

void Sieve_of_Eratosthenes()
{
    arr[1] = 0;
    for (int i = 2; i < 118; i++)
    {
        if (arr[i])
        {
            prime_num.push_back(i);
            for (int j = 2 * i; j < 118; j += i)
            {
                arr[j] = 0;
            }
        }
    }
}

bool check(int num)
{
    for (auto k : prime_num)
    {      
        if (find(prime_num.begin(), prime_num.end(), num - k) != prime_num.end())
        {
            return true;
        }      
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;

    Sieve_of_Eratosthenes();

    while (n--)
    {
        int num; cin >> num;
        if(check(num)) cout << "Yes\n";
        else cout << "No\n";
    }

    return 0;
}