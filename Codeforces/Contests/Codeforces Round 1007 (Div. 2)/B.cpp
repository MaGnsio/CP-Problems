/**
 *    author:  MaGnsi0
 *    created: 28.02.2025 16:40:05
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t N = 5e5;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    set<int64_t> squares;
    for (int64_t i = 1; i <= N; ++i) {
        squares.insert(i * i);
    }
    int T; cin >> T;
    while (T--) {
        int64_t n; cin >> n;
        if (squares.count(n * (n + 1) / 2)) {
            cout << "-1\n";
            continue;
        }
        int64_t sum = 0;
        set<int64_t> have;
        for (int i = 1; i <= n; ++i) {
            have.insert(i);
        }
        for (int i = 0; i < n; ++i) {
            int64_t first = *have.begin();
            if (i == n - 1) {
                cout << first << " ";
                have.erase(first);
                sum += first;
                continue;
            }
            int64_t second = *have.upper_bound(first);
            if (squares.count(sum + first)) {
                assert(squares.count(sum + second) == 0);
                cout << second << " ";
                have.erase(second);
                sum += second;
            } else {
                cout << first << " ";
                have.erase(first);
                sum += first;
            }
        }
        cout << "\n";
    }
}
