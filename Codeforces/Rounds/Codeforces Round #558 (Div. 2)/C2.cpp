/**
 *    author:  MaGnsi0
 *    created: 24.07.2023 15:44:51
**/
#include <bits/stdc++.h>

using namespace std;

const int OO = 1e8;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }
    map<pair<int, int>, set<pair<int, int>>> Lines;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int dx = x[j] - x[i];
            int dy = y[j] - y[i];
            if (dy == 0) {
                Lines[{0, OO}].emplace(y[i], 1);
            } else if (dx == 0) {
                Lines[{OO, 0}].emplace(x[i], 1);
            } else {
                int g1 = __gcd(dx, dy);
                dx /= g1, dy /= g1;
                if (dx < 0) {
                    dx *= -1;
                    dy *= -1;
                }
                int top = y[i] * x[j] - y[j] * x[i];
                int bot = x[j] - x[i];
                int g2 = __gcd(top, bot);
                top /= g2, bot /= g2;
                if (top < 0) {
                    top *= -1;
                    bot *= -1;
                }
                Lines[{dx, dy}].emplace(top, bot);
            }
        }
    }
    int64_t ans = 0;
    for (auto [_, s] : Lines) {
        ans += (int64_t)s.size();
    }
    ans = ans * (ans - 1) / 2;
    for (auto [_, s] : Lines) {
        ans -= (int64_t)s.size() * ((int64_t)s.size() - 1) / 2;
    }
    cout << ans;
}
