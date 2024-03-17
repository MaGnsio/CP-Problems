/**
 *    author:  MaGnsi0
 *    created: 02.01.2024 19:18:40
**/
#pragma GCC optimize("O3")
#pragma GCC target ("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i] >> b[i];
        }
        int ans = INT_MAX;
        for (int _ = 0; _ < 2; ++_) {
            int have_to = -1;
            unordered_map<int, int> mp2, mp3;
            map<int, vector<int>> mp1;
            for (int i = 0; i < n; ++i) {
                mp1[-a[i]].push_back(b[i]);
                mp2[b[i]]++, mp3[-a[i]]++;
            }
            set<int> opt(b.begin(), b.end());
            for (auto [x, c] : mp1) {
                while (!opt.empty() && *opt.begin() < have_to) {
                    opt.erase(opt.begin());
                }
                if (mp3[x] == 1 && mp2[c[0]] == 1) {
                    opt.erase(c[0]);
                }
                if (have_to != -1) {
                    ans = min(ans, abs(have_to + x));
                }
                if (!opt.empty()) {
                    auto it = opt.lower_bound(-x);
                    if (it != opt.end()) {
                        ans = min(ans, abs(*it + x));
                    }
                    if (it != opt.begin()) {
                        it--;
                        ans = min(ans, abs(*it + x));
                    }
                }
                for (int y : c) {
                    have_to = max(have_to, y);
                    mp2[y]--;
                }
            }
            swap(a, b);
        }
        cout << ans << "\n";
    }
}
