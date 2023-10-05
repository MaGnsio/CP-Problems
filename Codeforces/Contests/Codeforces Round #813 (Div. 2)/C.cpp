/**
 *    author:  MaGnsi0
 *    created: 13.08.2022 16:32:42
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
        set<int> changed;
        for (int i = n - 2; i >= 0; --i) {
            if (a[i] <= a[i + 1]) {
                continue;
            }
            for (int j = 0; j <= i; ++j) {
                changed.insert(a[j]);
            }
            for (int j = n - 1; j > i; --j) {
                if (!changed.count(a[j])) {
                    continue;
                }
                for (int k = i + 1; k <= j; ++k) {
                    changed.insert(a[k]);
                }
                break;
            }
            break;
        }
        cout << (int)changed.size() << "\n";
    }
}
