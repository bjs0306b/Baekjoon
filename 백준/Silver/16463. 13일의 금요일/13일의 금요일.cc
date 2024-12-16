#include <bits/stdc++.h>
using namespace std;

bool check_leap_year(int n){
    if(n%400 == 0) return true;
    if(n%100 == 0) return false;
    if(n%4 == 0) return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int current_day_of_the_week = 4;
    int leap_year[12] = {3,3,1,3,2,3,2,3,3,2,3,2}, common_year[12] = {3,3,0,3,2,3,2,3,3,2,3,2};
    int ans = 0;
    for(int i=2019; i<=n; i++){
        if(check_leap_year(i)) // 윤년일 때
        {
            for(int j=0;j<12;j++){
                current_day_of_the_week += leap_year[j];
                current_day_of_the_week %= 7;
                if(current_day_of_the_week == 5) ans++;
            }
        }
        else // 평년일 때
        {
            for(int j=0;j<12;j++){
                current_day_of_the_week += common_year[j];
                current_day_of_the_week %= 7;
                if(current_day_of_the_week == 5) ans++;
            }
        }
    }
    cout << ans;

    return 0;
}