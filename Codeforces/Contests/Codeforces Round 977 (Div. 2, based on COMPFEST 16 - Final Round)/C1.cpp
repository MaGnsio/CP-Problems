/**
 *    author:  MaGnsi0
 *    created: 07.10.2024 20:11:10
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int m; cin >> m;
        int Q; cin >> Q;
        assert(Q == 0);
        vector<int> a(n), b(m);
        for (int i = 0; i < n; ++i) {
            cin >> a[i]; a[i]--;
        }
        for (int i = 0; i < m; ++i) {
            cin >> b[i]; b[i]--;
        }
        bool good = true;
        set<int> can_read;
        for (int i = 0, j = 0; i < m && j < n; ++i) {
            if (b[i] == a[j]) {
                can_read.insert(a[j++]);
            }
            good = good && can_read.count(b[i]);
        }
        cout << (good ? "YA" : "TIDAK") << "\n";
    }
}
