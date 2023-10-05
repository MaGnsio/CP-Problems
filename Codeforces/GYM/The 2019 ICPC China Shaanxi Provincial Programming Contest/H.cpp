/**
 *    author:  MaGnsi0
 *    created: 16.09.2023 08:10:03
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<bool> is_prime(N, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i < N; ++i) {
        if (is_prime[i]) {
            for (int j = 2 * i; j < N; j += i) {
                is_prime[j] = false;
            }
        }
    }
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<bool> done(n + 1, false);
        vector<pair<int, int>> ans;
        for (int i = n; i > 1; --i) {
            if (!is_prime[i]) { continue; }
            vector<int> good;
            for (int j = i; j <= n; j += i) {
                if (done[j]) { continue; }
                good.emplace_back(j);
            }
            if ((int)good.size() == 1) { continue; }
            if ((int)good.size() & 1) {
                ans.emplace_back(good[0], good[2]);
                done[good[0]] = done[good[2]] = true;
                for (int j = 3; j < (int)good.size(); j += 2) {
                    ans.emplace_back(good[j], good[j + 1]);
                    done[good[j]] = done[good[j + 1]] = true;
                }
            } else {
                for (int j = 0; j < (int)good.size(); j += 2) {
                    ans.emplace_back(good[j], good[j + 1]);
                    done[good[j]] = done[good[j + 1]] = true;
                }
            }
        }
        cout << (int)ans.size();
        for (auto [x, y] : ans) {
            cout << " " << x << " " << y;
        }
        cout << "\n";
    }
}
