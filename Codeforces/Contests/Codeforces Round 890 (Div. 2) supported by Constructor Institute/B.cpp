/**
 *    author:  MaGnsi0
 *    created: 05.08.2023 22:23:11
**/
#include <bits/stdc++.h>

using namespace std;

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
        sort(a.begin(), a.end());
        if (n == 1) {
            cout << "NO\n";
        } else if (a[0] != 1) {
            cout << "YES\n";
        } else {
            int64_t sum = 0;
            for (int i = 0; i < n; ++i) {
                sum += a[i];
            }
            for (int i = 0; i < n - 1; ++i) {
                if (a[i] == 1) {
                    sum -= 2;
                } else {
                    sum -= 1;
                }
            }
            cout << (sum > 0 ? "YES" : "NO") << "\n";
        }
    }
}
