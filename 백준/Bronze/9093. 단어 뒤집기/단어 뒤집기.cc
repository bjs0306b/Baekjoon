/*
여러분의 코드에는 입력을 처리하는 방법과 관련된 문제가 있습니다.
cin >> n을 사용하여 n의 값을 읽을 때 이는 입력 버퍼에 개행 문자('\n')를 남깁니다.
이후에 루프 안에서 getline(cin, str)을 사용할 때 이 개행 문자가 빈 문자열로 읽혀
루프가 예상대로 동작하지 않는 문제가 발생합니다.
이를 해결하기 위해서 cin >> n 이후에 cin.ignore()를 추가하여 개행 문자를 소비하도록 해야 합니다.

계속 n에 2넣는데 1번만 반복하고 끝나길래 gpt에 검색하니 cin은 개행문자를 남겨서 ignore을 추가시키면 해결된다고 하네?
*/

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    cin.ignore();
    string str;
    while (n--)
    {
        getline(cin, str);
        int s = str.size();
        int t = 0;
        for (int j = 0; j < s - 1; j++)
        {
            if (str[j] == ' ')
            {
                reverse(str.begin() + t, str.begin() + j);
                t = j + 1;
            }
        }
        reverse(str.begin() + t, str.begin() + s);
        cout << str << "\n";
    }

    return 0;
}