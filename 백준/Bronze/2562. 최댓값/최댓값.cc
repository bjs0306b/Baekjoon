#include <stdlib.h>
#include <iostream>

using namespace std;

void find_M(int a[], int n)
{
  int max = a[0];
  int num = 1;
  for(int i=0;i<n;i++){
    if(max < a[i]) {
    max = a[i];
    num = i+1;
    }
  }  
  cout << max << endl << num;
}

int main(){
  int a[9];
  for(int i=0;i<9;i++) cin >> a[i];
  
  find_M(a, 9);
  
  return 0;
}
