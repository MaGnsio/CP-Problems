/**
 *    author:  MaGnsi0
 *    created: 06.06.2023 19:56:11
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t N = 1e6, Q = 333;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int x; cin >> x;
    function<int64_t(int64_t)> ask = [&](int64_t x) {
        cout << "+ " << x << endl;
        int64_t v;
        cin >> v;
        return v;
    };
    function<void(int64_t)> guess = [&](int64_t x) {
        cout << "! " << x << endl;
        exit(0);
    };
    function<int64_t(int64_t, int64_t)> random = [&](int64_t x, int64_t y) {
        return uniform_int_distribution<int64_t>(x, y)(rng);
    };
    int64_t m = 0;
    for (int64_t i = 1; i <= Q; ++i) {
        m = max(m, ask(random(1, N)));
    }
    map<int64_t, int64_t> mp;
    for (int64_t i = 1; i <= Q; ++i) {
        int64_t cur_v = ask(1);
        if (mp.count(cur_v)) {
            guess(i - mp[cur_v]);
        }
        mp[cur_v] = i;
    }
    int64_t cur_v = ask(m);
    if (mp.count(cur_v)) {
        guess(m + Q - mp[cur_v]);
    }
    for (int64_t i = 1; i <= Q; ++i) {
        int64_t cur_v = ask(Q);
        if (mp.count(cur_v)) {
            guess((i + 1) * Q + m - mp[cur_v]);
        }
    }
}
