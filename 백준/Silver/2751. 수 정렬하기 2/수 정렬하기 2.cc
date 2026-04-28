#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  int t;
  cin >> t;

  vector<int> numbers(t);

  for(int i=0;i<t;i++)  cin >> numbers[i];

  sort(numbers.begin(), numbers.end());

  for(int i=0;i<t;i++)  cout << numbers[i] << '\n';
     
  return 0;
}