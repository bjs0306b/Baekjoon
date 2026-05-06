#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;
map<int,int> total_time; // total_time[a] = b, 차량 번호가 a인 차량은 b분 사용함.
map<int, pair<int,int>> enter_time;

vector<int> solution(vector<int> fees, vector<string> records) { 
    for(auto k : records){
        int hour = stoi(k.substr(0, 2));
        int minute = stoi(k.substr(3, 2));
        int car_num = stoi(k.substr(6, 4));
        string in_or_out = k.substr(11);
        
        if(in_or_out == "IN"){
            enter_time[car_num] = {hour, minute};
        }
        else{
            int s_hour = enter_time[car_num].first;
            int s_min = enter_time[car_num].second;
            int dif_hour = hour - s_hour;
            int dif_min = minute - s_min + dif_hour * 60;
            total_time[car_num] += dif_min;
            enter_time.erase(car_num);
        }
    }
    for(auto k : enter_time){
        int car_num = k.first;
        int hour = k.second.first;
        int minute = k.second.second;

        int dif_hour = 23 - hour;
        int dif_min = 59 - minute + dif_hour * 60;
        total_time[car_num] += dif_min;
    }
    vector<int> answer;
    for(auto k : total_time){
        int price = fees[1];
        if(k.second > fees[0]){
            price += (k.second - fees[0] + fees[2] - 1) / fees[2] * fees[3];
        }
        answer.push_back(price);
    }
    
    return answer;
    
}