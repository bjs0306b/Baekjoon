#include <bits/stdc++.h>
using namespace std;

string s;

bool dfs(int index) {
    if (index == (int)s.size()) return true;

    // 패턴 시작이 '0'인 경우: "01" 패턴
    if (s[index] == '0') {
        // "01" 이므로 다음 문자가 '1'이어야 함
        if (index + 1 >= (int)s.size()) return false;
        if (s[index + 1] == '1') {
            // "01"을 처리했으니 그 다음 인덱스부터 다시 검사
            return dfs(index + 2);
        }
        return false;
    } 
    else { 
        // 패턴 시작이 '1'인 경우: "100+1+" 패턴
        // 최소 길이 4 이상이어야 하므로 길이 검사
        if (index + 3 >= (int)s.size()) return false;

        int i = index + 1;

        // '0'이 최소 2개 이상 연속으로 나와야 함
        int zero_count = 0;
        while (i < (int)s.size() && s[i] == '0') {
            zero_count++;
            i++;
            if (zero_count == 1 && i >= (int)s.size()) return false; // 최소 2개여야 하므로 이른 종료 체크
        }
        if (zero_count < 2) return false;

        // '1'이 최소 1개 이상 연속으로 나와야 함
        int one_count = 0;
        while (i < (int)s.size() && s[i] == '1') {
            one_count++;
            i++;
        }
        if (one_count < 1) return false;

        // 재귀 호출:
        // - 현재까지 '100+1+' 패턴을 처리했으니 그 다음 인덱스부터 다시 검사
        // - 단, '1'이 여러 개일 때 일부를 다음 패턴 시작으로 사용할 수도 있으므로 i-1 위치부터도 검사
        // 즉, '1'이 2개 이상인 경우 두 가지 경우 모두 검사
        if (one_count > 1) {
            // i-1 위치부터 시작하거나 i 위치부터 시작하거나 모두 시도
            return dfs(i - 1) || dfs(i);
        } else {
            return dfs(i);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; 
    cin >> n;
    while (n--) {
        cin >> s;
        if (dfs(0)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
