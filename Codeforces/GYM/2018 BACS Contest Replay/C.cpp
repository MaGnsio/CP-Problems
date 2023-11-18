/**
 *    author:  MaGnsi0
 *    created: 20.10.2023 16:10:48
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; ++t) {
        int m; cin >> m;
        int n; cin >> n;
        vector<int64_t> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        bool ok = false;
        int64_t sum = accumulate(a.begin(), a.end(), int64_t(0));
        for (int i = 1; i < n; ++i) {
            ok |= (a[i] - a[i - 1] == 1);
        }
        cout << "Case " << t << ": ";
        cout << "Thank You BACS!!! ";
        cout << (sum == m ? "Thik ache." : "Bojjat dokandar!!");
        cout << (ok ? " Yes" : " No") << "\n";
    }
}
