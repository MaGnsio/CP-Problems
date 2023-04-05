/**
 *    author:  MaGnsi0
 *    created: 25.12.2022 19:25:49
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int64_t n, x;
    cin >> n >> x;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    vector<tuple<int64_t, int64_t, int>> c(n);
    for (int i = 0; i < n; ++i) {
        c[i] = make_tuple(a[i], b[i], i);
    }
    sort(c.begin(), c.end());
    vector<int> ans(n, 0);
    set<pair<int64_t, int>> diff, A, B;
    for (int64_t i = 0; i < n; ++i) {
        if (get<0>(c[i]) <= x) {
            x -= get<0>(c[i]);
            ans[get<2>(c[i])] = 1;
            diff.emplace(get<1>(c[i]) - get<0>(c[i]), get<2>(c[i]));
            A.emplace(get<0>(c[i]), get<2>(c[i]));
        } else {
            B.emplace(get<1>(c[i]), get<2>(c[i]));
        }
    }
    while (true) {
        auto it = diff.begin();
        auto it2 = A.rbegin();
        auto it3 = B.begin();
        int64_t choice1 = (diff.empty() ? INT64_MAX : it -> first);
        int64_t choice2 = (A.empty() || B.empty() ? INT64_MAX : (it3 -> first) - (it2 -> first));
        if (choice1 == INT64_MAX && choice1 == INT64_MAX) {
            break;
        }
        if (choice1 < choice2 && x - choice1 >= 0) {
            ans[it -> second] = 2;
            A.erase(make_pair(a[it -> second], it -> second));
            diff.erase(it);
            x -= choice1;
        } else if (x - choice2 >= 0) {
            ans[it2 -> second] = 0;
            ans[it3 -> second] = 2;
            B.emplace(b[it2 -> second], it2 -> second);
            diff.erase(make_pair(b[it2 -> second] - a[it2 -> second], it2 -> second));
            A.erase(make_pair(it2 -> first, it2 -> second));
            B.erase(it3);
            x -= choice2;
        } else {
            break;
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << ans[i];
    }
}
