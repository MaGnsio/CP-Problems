/**
 *    author:  MaGnsi0
 *    created: 29.12.2021 23:25:10
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> A(n), B(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> B[i];
    }
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; ++i) {
        int x, y;
        cin >> x >> y;
        cout << (A[x - 1] > n - B[y - 1] ? "#" : ".");
    }
}
