#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include<memory.h>
#include <stdio.h>
using namespace std;
int n,ans;
int arr[4] = { 1,5,10,50 };
bool check[1001];
void go(int index,int sum,int cnt) {
	if (cnt == n) { 
		if (check[sum]) return; 
		check[sum] = true;
		ans++;
		return;
	}
	for (int i = index; i < 4; i++) {
		go(i,sum + arr[i], cnt + 1);
	}
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL);
	cin >> n;
	go(0, 0, 0);
	cout << ans;
}