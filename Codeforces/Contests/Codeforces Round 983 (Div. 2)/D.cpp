/**
 *    author:  MaGnsi0
 *    created: 01.11.2024 17:08:51
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    function<int(int, int)> ask = [&](int u, int v) {
        cout << "? " << u << " " << v << endl;
        int x; cin >> x; return x;
    };
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> p(n);
        for (int v = 2; v < n; ++v) {
            if (ask(1, v)) { continue; }
            p[v] = 1;
            for (int u = v + 1, p_ = 2; u < n; ++u) {
                while (ask(p_, u)) { p_++; }
                p[u] = p_++;
            }
            break;
        }
        cout << "!";
        for (int i = 1; i < n; ++i) {
            cout << " " << p[i];
        }
        cout << endl;
    }
}
