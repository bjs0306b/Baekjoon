#include <iostream>
#include <vector>
using namespace std;
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	while (1) {
		int n, m; //CD의 갯수(사람1의 CD 갯수 n, 사람2의 CD 갯수 m)
		int cnt = 0; //공통된 CD의 갯수
		int num; //CD의 번호
		int it1 = 0, it2 = 0; //v1을 순회하는 이터레이터, v2를 순회하는 이터레이터
		vector<int> v1; //사람1
		vector<int> v2; //사람2
		
		cin >> n >> m;
		if (n == 0 && m == 0) { //0, 0입력이면
			break; //종료
		}
 
		//CD번호를 입력
		for (int i = 0; i < n; i++) {
			cin >> num;
			v1.push_back(num);
		}
		for (int i = 0; i < m; i++) {
			cin >> num;
			v2.push_back(num);
		}
 
		while (1) {
			if (it1 == v1.size() || it2 == v2.size()) { //이터레이터가 돌다가 두 개중 하나라도 마지막 인덱스를 넘으면 
				break; //종료
			}
			if (v1[it1] == v2[it2]) { //공통된 수이면 이터레이터 증가 후 공통된 CD의 갯수 증가
				it1++;
				it2++;
				cnt++;
			}
			else if (v1[it1] < v2[it2]) { //현재 v1의 수가 v2의 수보다 작으면
				it1++; //v1의 이터레이터 증가
			}
			else { //현재 v2의 수가 v1의 수보다 작으면
				it2++; //v2의 이터레이터 증가
			}
		}
		cout << cnt << '\n'; 
	}
}