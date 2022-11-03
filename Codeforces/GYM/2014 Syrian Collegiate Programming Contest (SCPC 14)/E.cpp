/**
 *    author:  MaGnsi0
 *    created: 28.09.2022 18:21:02
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int n, k;
        cin >> n >> k;
        map<int64_t, int> grundy;
        function<int(int64_t)> F = [&](int64_t x) {
            if (grundy.count(x)) {
                return grundy[x];
            }
            set<int> s;
            for (int i = k - 1; i < n; ++i) {
                int64_t to_remove = ((1LL << k) - 1) & (x >> (i - k + 1));
                if (__builtin_popcountll(to_remove) != k) { continue; }
                int pile1 = F(x & ((1LL << (i - k + 1)) - 1));
                int pile2 = F(x & ~((1LL << (i + 1)) - 1));
                s.insert(pile1 ^ pile2);
            }
            grundy[x] = 0;
            while (s.count(grundy[x])) {
                grundy[x]++;
            }
            return grundy[x];
        };
        cout << "Case " << t << ": " << (F((1LL << n) - 1) ? "Winning" : "Losing") << "\n"; 
    }
}
