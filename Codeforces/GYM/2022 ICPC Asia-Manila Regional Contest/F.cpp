/**
 *    author:  MaGnsi0
 *    created: 25.12.2022 18:21:46
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int64_t> W(n);
    for (int i = 0; i < n; ++i) {
        cin >> W[i];
    }
    int64_t cur_sum = accumulate(W.begin(), W.end(), int64_t(0));
    set<int> cur_alive, neg_cur_alive;
    set<pair<int64_t, int>> WI;
    for (int i = 0; i < n; ++i) {
        cur_alive.emplace(i);
        neg_cur_alive.emplace(-i);
        WI.emplace(W[i], i);

    }
    while ((int)cur_alive.size() > 1) {
        int64_t maxW = WI.rbegin() -> first;
        if (maxW <= cur_sum - maxW) {
            int j = WI.lower_bound(make_pair(maxW, -1)) -> second;
            auto it1 = cur_alive.upper_bound(j);
            if (it1 != cur_alive.end()) {
                int i = *it1;
                WI.erase(make_pair(W[i], i));
                W[i] += maxW / 2;
                WI.emplace(W[i], i);
            } else {
                cur_sum -= maxW / 2;
            }
            auto it2 = neg_cur_alive.upper_bound(-j);
            if (it2 != neg_cur_alive.end()) {
                int i = -*it2;
                WI.erase(make_pair(W[i], i));
                W[i] += maxW / 2;
                WI.emplace(W[i], i);
            } else {
                cur_sum -= maxW / 2;
            }
            WI.erase(make_pair(maxW, j));
            cur_alive.erase(j);
            neg_cur_alive.erase(-j);
            cur_sum -= maxW % 2;
            cout << j + 1 << " " << maxW << "\n";
        } else {
            int j = WI.begin() -> second;
            int64_t minW = WI.begin() -> first;
            auto it1 = cur_alive.upper_bound(j);
            if (it1 != cur_alive.end()) {
                int i = *it1;
                WI.erase(make_pair(W[i], i));
                W[i] += minW / 2;
                WI.emplace(W[i], i);
            } else {
                cur_sum -= minW / 2;
            }
            auto it2 = neg_cur_alive.upper_bound(-j);
            if (it2 != neg_cur_alive.end()) {
                int i = -*it2;
                WI.erase(make_pair(W[i], i));
                W[i] += minW / 2;
                WI.emplace(W[i], i);
            } else {
                cur_sum -= minW / 2;
            }
            WI.erase(make_pair(minW, j));
            cur_alive.erase(j);
            neg_cur_alive.erase(-j);
            cur_sum -= minW % 2;
            cout << j + 1 << " " << minW << "\n";
        }
    }
    cout << WI.begin() -> second + 1 << " " << WI.begin() -> first;
}
