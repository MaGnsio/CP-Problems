/**
 *    author:  MaGnsi0
 *    created: 13.02.2024 13:55:14
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int64_t n; cin >> n;
    int Q; cin >> Q;
    int m = 0;
    map<int, int64_t> pos;
    map<int64_t, int> who;
    set<int64_t> all_pos, all_neg;
    set<tuple<int64_t, int64_t, int64_t>> options;
    function<int64_t(int64_t)> get_prev = [&](int64_t x) {
        auto it = all_neg.upper_bound(-x);
        if (it == all_neg.end()) { return int64_t(-1); }
        return -*it;
    };
    function<int64_t(int64_t)> get_next = [&](int64_t x) {
        auto it = all_pos.upper_bound(x);
        if (it == all_pos.end()) { return int64_t(-1); }
        return *it;
    };
    function<void(int64_t, int64_t)> add_option = [&](int64_t L, int64_t R) {
        if (L == -1 || R == -1) { return; }
        if (L + 1 == R) { return; }
        int64_t D = (R - L) / 2;
        D = min(D, R - L - D);
        options.emplace(-D, L, R);
    };
    function<void(int64_t, int64_t)> rem_option = [&](int64_t L, int64_t R) {
        if (L == -1 || R == -1) { return; }
        if (L + 1 == R) { return; }
        int64_t D = (R - L) / 2;
        D = min(D, R - L - D);
        options.erase(make_tuple(-D, L, R));
    };
    while (Q--) {
        char c; cin >> c;
        if (c == '+') {
            if (all_pos.empty()) {
                pos[++m] = 1, who[1] = m;
                all_pos.emplace(pos[m]);
                all_neg.emplace(-pos[m]);
            } else {
                int64_t optL = *all_pos.begin() - 1;
                int64_t optM = -get<0>(*options.begin());
                int64_t optR = n - *all_pos.rbegin();
                if (optL >= optM && optL >= optR) {
                    int64_t next = get_next(1);
                    add_option(1, next);
                    pos[++m] = 1, who[1] = m;
                    all_pos.emplace(pos[m]);
                    all_neg.emplace(-pos[m]);
                } else if (optM >= optL && optM >= optR) {
                    int64_t prev = get<1>(*options.begin());
                    int64_t next = get<2>(*options.begin());
                    int64_t place = prev - get<0>(*options.begin());
                    options.erase(options.begin());
                    add_option(prev, place);
                    add_option(place, next);
                    pos[++m] = place, who[place] = m;
                    all_pos.emplace(pos[m]);
                    all_neg.emplace(-pos[m]);
                } else {
                    int64_t prev = get_prev(n);
                    add_option(prev, n);
                    pos[++m] = n, who[n] = m;
                    all_pos.emplace(pos[m]);
                    all_neg.emplace(-pos[m]);
                }
            }
            cout << pos[m] << "\n";
        } else {
            int j; cin >> j;
            int64_t place = pos[j];
            int64_t prev = get_prev(place);
            int64_t next = get_next(place);
            pos.erase(j); who.erase(place);
            all_pos.erase(place);
            all_neg.erase(-place);
            rem_option(prev, place);
            rem_option(place, next);
            add_option(prev, next);
        }
    }
}
