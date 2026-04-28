#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    string month, day; cin >> month >> day;
    int year; cin >> year;
    string time; cin >> time;
    day = day.substr(0,day.size()-1);
    int int_day = stoi(day);   
    int hour = stoi(time.substr(0,2));
    int minute = stoi(time.substr(3,2));

    if(month == "January") int_day += 0;
    else if(month == "February") int_day += 31;
    else if(month == "March") int_day += 59;
    else if(month == "April") int_day += 90;
    else if(month == "May") int_day += 120;
    else if(month == "June") int_day += 151;
    else if(month == "July") int_day += 181;
    else if(month == "August") int_day += 212;
    else if(month == "September") int_day += 243;
    else if(month == "October") int_day += 273;
    else if(month == "November") int_day += 304;
    else if(month == "December") int_day += 334;
    
    int_day--;

    hour += int_day*24;
    minute += hour*60;
    bool yoon = false;
    if(year%400 == 0 || (year%4 == 0 && year%100 != 0)) yoon = true;
    int total_minutes;
    if(yoon) total_minutes = 366*24*60;
    else total_minutes =365*24*60;
    if(yoon && month != "January" && month != "February")
        minute += 60*24;
    
    double ans = (double)minute/total_minutes*100;
    cout << fixed << setprecision(9) << ans;

    
    
    return 0;
}