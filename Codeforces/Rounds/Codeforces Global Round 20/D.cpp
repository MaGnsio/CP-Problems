/**
 *    author:  MaGnsi0
 *    created: 23.04.2022 15:57:38
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
vector<int> F(N, 0);

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n), c(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        c[0] = 1;
        for (int i = 1; i < n; ++i) {
            c[i] = (b[i] == b[i - 1] ? c[i - 1] + 1 : 1);
        }
        if (a[n - 1] != b[n - 1]) {
            cout << "NO\n";
            continue;
        }
        int offset = 0;
        bool ok = true;
        for (int i = n - 1; i >= 0; --i) {
            if (!F[a[i]] && a[i] != b[i - offset]) {
                ok = false;
                break;
            }
            if (a[i] != b[i - offset]) {
                F[a[i]]--;
                offset--;
                continue;
            }
            int x = offset;
            offset += c[i - x] - 1;
            F[a[i]] += c[i - x] - 1;
        }
        for (int i = 0; i < n; ++i) {
            F[a[i]] = 0;
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
}
