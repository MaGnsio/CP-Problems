/**
 *    author:  MaGnsi0
 *    created: 27.04.2024 17:36:16
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        int first = (a[0] != 1 ? 1 : -1), count = 1;
        for (int i = 1; i < n; ++i) {
            if (first != -1) { break; }
            count += a[i] != a[i - 1];
            if (a[i] - a[i - 1] > 1) {
                first = count;
                break;
            }
        }
        if (first == -1) {
            cout << ((count & 1) ? "Alice" : "Bob") << "\n";
        } else {
            cout << ((first & 1) ? "Alice" : "Bob") << "\n";
        }
    }
}
