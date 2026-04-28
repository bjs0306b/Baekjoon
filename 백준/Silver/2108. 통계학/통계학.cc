#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n;
    vector<int> vec;
    vector<int>::iterator iter;
    int num1,num2,num3,num4;
    int max = -4000;
    int min = 4000;
    int arr[8001];
    int sum = 0;
    for(int i=0;i<8001;i++) arr[i]=0;

    for(int i=0;i<n;i++){
        int num;
        cin >> num;
        sum += num;
        if(num > max) max = num;
        if(num < min) min = num;
        arr[num+4000]++;
        vec.push_back(num);
    }
    float temp = (float)sum/n;
    if(temp >= 0) temp+=0.5;
    else temp-=0.5;
    num1 = static_cast<int>(temp);
    int max2=0;
    vector<int> vec2;
    for(int i=0;i<8001;i++)
        if(arr[i] > max2)
            max2 = arr[i];
    for(int i=0;i<8001;i++)
        if(arr[i] == max2)
            vec2.push_back(i-4000);
    sort(vec2.begin(), vec2.end());
    if(vec2.size() == 1) num3 = vec2[0];
    else num3 = vec2[1];
    num4 = max-min;
    sort(vec.begin(), vec.end());
    num2 = vec[n/2];

    cout << num1 << "\n" << num2 << "\n" << num3 << "\n" << num4;
    
    return 0;
}