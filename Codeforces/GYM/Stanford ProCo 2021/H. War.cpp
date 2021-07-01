/**
 *    author:  MaGnsi0
 *    created: 11/06/2021 21:36:49
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n, ans = 0;
    cin >> n;
    vector<int> A(n), B(n);
    for (auto& a : A) {
        cin >> a;
    }
    sort(A.begin(), A.end());
    for (auto& b : B) {
        cin >> b;
    }
    sort(B.begin(), B.end());
    for (int i = 0, j = 0; i < n; ++i) {
        if (A[i] > B[j]) {
            ans++;
            j++;
        }
    }
    cout << ans;
}
