#include <bits/stdc++.h>
using namespace std;

int prime_num[10000];

void prime_check()
{

    for (int i = 2; i < 10000; i++)
    {
        if (prime_num[i])
        {
            for (int j = i * 2; j < 10000; j += i)
                prime_num[j] = false;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 2; i < 10000; i++)
        prime_num[i] = true;
    prime_check();

    while (n--)
    {
        int a, b;
        cin >> a >> b;

        queue<int> q;
        q.push(a);
        vector<bool> visited(10000, 0);
        visited[a] = true;

        int cnt = 0;
        bool flag = false;
        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                int front = q.front();
                if(front == b){
                    cout << cnt << "\n";
                    flag = true;
                    break;
                }
                q.pop();
                for(int k = 1; k != 10000; k *= 10){
                    for (int j = 0; j < 10; j++)
                    {
                        if (!visited[front - front % (k*10) + front % k + j * k] && prime_num[front - front % (k*10) + front % k + j * k] && front - front % (k*10) + front % k + j * k > 1000)
                        {
                            //cout << front - front % (k*10) + front % k + j * k << " ";
                            q.push(front - front % (k*10) + front % k + j * k);
                            visited[front - front % (k*10) + front % k + j * k] = true;
                        }
                    }
                }
            }
            if(flag) break;
            cnt++;
        }
    }

    return 0;
}