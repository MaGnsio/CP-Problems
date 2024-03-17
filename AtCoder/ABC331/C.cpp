/**
 *    author:  MaGnsi0
 *    created: 02.12.2023 14:08:44
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int64_t> a(n), b(N);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        b[a[i]] += a[i];
    }
    for (int i = N - 2; i >= 0; --i) {
        b[i] += b[i + 1];
    }
    for (int i = 0; i < n; ++i) {
        cout << b[a[i] + 1] << " ";
    }
}
