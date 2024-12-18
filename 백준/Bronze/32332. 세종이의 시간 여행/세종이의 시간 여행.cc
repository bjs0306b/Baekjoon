#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int current_y, current_m, current_d;
    double current_latitude, current_hardness; // 현재 년, 월, 일, 위도, 경도
    cin >> current_y >> current_m >> current_d >> current_latitude >> current_hardness;
    int moving_y, moving_m, moving_d;
    double moving_latitude, moving_hardness; // 이동하려는 년, 월, 일, 위도, 경도
    cin >> moving_y >> moving_m >> moving_d >> moving_latitude >> moving_hardness;
    int real_y, real_m, real_d;
    double real_latitude, real_hardness; // 실제 이동한 년, 월, 일, 위도, 경도

    real_y = 2*current_y - moving_y,  real_m = 2*current_m - moving_m,  real_d = 2*current_d - moving_d;
    real_latitude = 2*current_latitude - moving_latitude,  real_hardness = 2*current_hardness - moving_hardness;

    if(real_d <= 0){
        real_d += 30;
        real_m--;
    }
    else if(real_d > 30){
        real_d -= 30;
        real_m++;
    }
    if(real_m <= 0){
        real_m += 12;
        real_y--;
    }
    else if(real_m > 12){
        real_m -= 12;
        real_y++;
    }
    cout << real_y <<" "<< real_m <<" "<< real_d <<" ";
    cout << fixed << setprecision(3);
    cout << real_latitude <<" "<< real_hardness;

    return 0;
}