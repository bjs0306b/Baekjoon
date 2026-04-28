#include <iostream>
#include <algorithm>
using namespace std;

int found_num(int* arr, int size, int key) {
    auto lower = lower_bound(arr, arr + size, key);
    auto upper = upper_bound(arr, arr + size, key);
    return upper - lower;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;

    cin >> n;
    int arr1[n];
    for (int i = 0; i < n; i++) cin >> arr1[i];
    sort(arr1, arr1 + n);
    cin >> m;
    int arr2[m];
    for (int i = 0; i < m; i++) cin >> arr2[i];

    for (int i = 0; i < m; i++) {
        cout << found_num(arr1, n, arr2[i]) << " ";
    }

    return 0;
}
