/**
 *    author:  MaGnsi0
 *    created: 10.07.2022 16:32:28
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, q;
        cin >> n >> q;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        map<int, int> first, last;
        for (int i = n - 1; i >= 0; --i) {
            first[a[i]] = i;
        }
        for (int i = 0; i < n; ++i) {
            last[a[i]] = i;
        }
        for (int i = 0; i < q; ++i) {
            int from, to;
            cin >> from >> to;
            if (first.count(from) && last.count(to) && first[from] <= last[to]) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
}
