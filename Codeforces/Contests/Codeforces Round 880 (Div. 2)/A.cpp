/**
 *    author:  MaGnsi0
 *    created: 18.06.2023 17:36:11
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector<int> b(N);
        for (int i = 0; i < n; ++i) {
            b[a[i]]++;
        }
        bool ok = true;
        for (int i = 1; i < N; ++i) {
            ok &= b[i] <= b[i - 1];
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
}
