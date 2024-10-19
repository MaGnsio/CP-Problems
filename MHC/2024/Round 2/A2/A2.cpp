/**
 *    author:  MaGnsi0
 *    created: 19.10.2024 20:45:31
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<int64_t> L, R;
    for (int k = 1; 2 * k + 1 <= 18; ++k) {
        string half = "";
        function<void(int, int)> build_half = [&](int p, int d) {
            if (p == k) {
                string l = half;
                string r = half; r.pop_back();
                reverse(r.begin(), r.end());
                int m = (int)l.size();
                if (m == 1 || l[m - 2] != l[m - 1]) {
                    L.push_back(stoll(l));
                }
                if (!r.empty()) {
                    R.push_back(stoll(r));
                }
                return;
            }
            for (int d_ = d; d_ <= 9; ++d_) {
                half += char('0' + d_);
                build_half(p + 1, d_);
                half.pop_back();
            }
        };
        build_half(0, 1);
    }
    set Ls(L.begin(), L.end());
    set Rs(R.begin(), R.end());
    int T; cin >> T;
    for (int t = 1; t <= T; ++t) {
        cout << "Case #" << t << ": ";
        int64_t A; cin >> A;
        int64_t B; cin >> B;
        int64_t M; cin >> M;
        vector<int64_t> p10(10, 1);
        for (int i = 1; i < 10; ++i) {
            p10[i] = p10[i - 1] * 10;
        }
        vector Rmod(10, vector<map<int, vector<int>>>(10));
        for (int64_t r : Rs) {
            int kr = (int)to_string(r).size();
            int dr = to_string(r)[0] - '0';
            Rmod[kr][dr][r % M].push_back(r);
        }
        int64_t ans = 0;
        for (int64_t l : Ls) {
            int kl = (int)to_string(l).size();
            int dl = to_string(l).back() - '0';
            int kr = kl - 1;
            if (kr == 0) {
                ans += A <= l && l <= B && l % M == 0;
                continue;
            }
            int64_t wanted_mod = (M - l % M * p10[kr] % M) % M;
            for (int dr = 1; dr < dl; ++dr) {
                int64_t l_ = A - l * p10[kr];
                int64_t r_ = B - l * p10[kr];
                int64_t add = upper_bound(Rmod[kr][dr][wanted_mod].begin(), Rmod[kr][dr][wanted_mod].end(), r_)
                            - lower_bound(Rmod[kr][dr][wanted_mod].begin(), Rmod[kr][dr][wanted_mod].end(), l_);
                ans += add;
            }
        }
        cout << ans << "\n";
    }
}
