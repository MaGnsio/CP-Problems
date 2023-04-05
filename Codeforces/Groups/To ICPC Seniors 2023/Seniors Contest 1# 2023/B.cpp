/**
 *    author:  MaGnsi0
 *    created: 04.02.2023 09:48:58
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<pair<int64_t, int64_t>> a(5);
    for (int i = 0; i < 5; ++i) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end());
    int64_t x;
    cin >> x;
    if (a[4].first == 0) {
        if (x == 0) {
            for (int i = 0; i < 5; ++i) {
                int64_t s = 101LL * 101 * 101 * 101 * 5050;
                cout << s << " ";
            }
        } else {
            cout << "0 0 0 0 0";
        }
        return 0;
    }
    vector<int64_t> ans(5, 0);
    for (int64_t i = 0; i <= 100; ++i) {
        for (int64_t j = 0; j <= 100; ++j) {
            for (int64_t k = 0; k <= 100; ++k) {
                for (int64_t l = 0; l <= 100; ++l) {
                    int64_t x5 = x - (i * a[0].first + j * a[1].first + k * a[2].first + l * a[3].first);
                    if (x5 >= 0 && x5 % a[4].first == 0 && x5 / a[4].first <= 100) {
                        ans[a[0].second] += i, ans[a[1].second] += j;
                        ans[a[2].second] += k, ans[a[3].second] += l;
                        ans[a[4].second] += x5 / a[4].first;
                    }
                }
            }
        }
    }
    for (int i = 0; i < 5; ++i) {
        cout << ans[i] << " ";
    }
}
