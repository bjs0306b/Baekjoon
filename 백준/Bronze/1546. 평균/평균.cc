#include <stdlib.h>
#include <iostream>
using namespace std;

int max_arr(int n[], int size)
{
  int max = 0;
  for(int i=0;i<size;i++)
  {
    if(max < n[i])
      max = n[i];
  }
  return max;
}
int main(){
  int t;
  cin >> t;
  int arr[t];
  int sum = 0;
  for(int i=0;i<t;i++){
    cin >> arr[i];
    sum += arr[i];
  }

  int max = max_arr(arr, t);

  float fake_aver = static_cast<float>(sum)/static_cast<float>(max)*100/t;

  printf("%.5f", fake_aver);
  return 0;
}
