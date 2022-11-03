/**
 *    author:  MaGnsi0
 *    created: 25.07.2022 08:27:05
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<int> A(4);
    for (int i = 0; i < 4; ++i) {
        cin >> A[i];
    }
    if (A[1] < A[2] || A[3] < A[0]) {
        cout << 0;
    } else {
        sort(A.begin(), A.end());
        cout << A[2] - A[1];
    }
}
