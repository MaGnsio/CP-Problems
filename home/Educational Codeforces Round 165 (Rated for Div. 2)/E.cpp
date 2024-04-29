/**
 *    author:  MaGnsi0
 *    created: 29.04.2024 18:59:14
**/
#include <bits/stdc++.h>

using namespace std;

const int OO = 1e7;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i]; a[i]--;
        }
        map<int, vector<int>> mp;
        for (int i = 0; i < n; ++i) {
            mp[a[i]].push_back(i);
        }
        for (int i = 0; i < n; ++i) {
            reverse(mp[i].begin(), mp[i].end());
        }
        vector<int> S(4 * n, OO), L(4 * n, 0);
        function<void(int)> push = [&](int j) {
            S[2 * j + 1] += L[j]; L[2 * j + 1] += L[j];
            S[2 * j + 2] += L[j]; L[2 * j + 2] += L[j];
            L[j] = 0;
        };
        function<void(int, int, int, int, int, int)> update_ = [&](int j, int low, int high, int from, int to, int add) {
            if (high < from || to < low) { return; }
            if (from <= low && high <= to) {
                S[j] += add; L[j] += add;
                if (low != high) { push(j); }
                return;
            }
            int mid = (low + high) / 2;
            push(j);
            update_(2 * j + 1, low, mid, from, to, add);
            update_(2 * j + 2, mid + 1, high, from, to, add);
            S[j] = min(S[2 * j + 1], S[2 * j + 2]);
        };
        function<void(int, int, int)> update = [&](int from, int to, int add) {
            update_(0, 0, n - 1, from, to, add);
        };
        function<int(int, int, int, int, int)> query_ = [&](int j, int low, int high, int from, int to) {
            if (high < from || to < low) { return OO; }
            if (from <= low && high <= to) { return S[j]; }
            int mid = (low + high) / 2;
            push(j);
            return min(query_(2 * j + 1, low, mid, from, to), query_(2 * j + 2, mid + 1, high, from, to));
        };
        function<int(int, int)> query = [&](int from, int to) {
            return query_(0, 0, n - 1, from, to);
        };
        update(0, n - 1, -OO);
        for (int i = 0; i < n; ++i) {
            if ((int)mp[i].size() >= 2) {
                int j = mp[i][mp[i].size() - 2];
                update(j, n - 1, -1);
            }
            if ((int)mp[i].size() >= 1) {
                int j = mp[i][mp[i].size() - 1];
                update(j, n - 1, 1);
            }
        }
        int ans = 0;
        function<void(int)> solve = [&](int i) {
            if (i == n) { return; }
            int low = i, high = n - 1, bad = -1;
            while (low <= high) {
                int mid = (low + high) / 2;
                if (query(i, mid) == 0) {
                    bad = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            if (bad == -1 || ((a[bad] == a[i]) && (bad != i + 1))) {
                if ((int)mp[a[i]].size() >= 2) {
                    int j = mp[a[i]][mp[a[i]].size() - 2];
                    update(j, n - 1, 1);
                }
                if ((int)mp[a[i]].size() >= 1) {
                    int j = mp[a[i]][mp[a[i]].size() - 1];
                    update(j, n - 1, -1);
                }
                assert(mp[a[i]].back() == i);
                mp[a[i]].pop_back();
                if ((int)mp[a[i]].size() >= 2) {
                    int j = mp[a[i]][mp[a[i]].size() - 2];
                    update(j, n - 1, -1);
                }
                if ((int)mp[a[i]].size() >= 1) {
                    int j = mp[a[i]][mp[a[i]].size() - 1];
                    update(j, n - 1, 1);
                }
                solve(i + 1);
                return;
            }
            ans++;
            set<int> updates;
            for (int k = i; k <= bad; ++k) {
                updates.insert(a[k]);
            }
            for (int x : updates) {
                if ((int)mp[x].size() >= 2) {
                    int j = mp[x][mp[x].size() - 2];
                    update(j, n - 1, 1);
                }
                if ((int)mp[x].size() >= 1) {
                    int j = mp[x][mp[x].size() - 1];
                    update(j, n - 1, -1);
                }
            }
            for (int k = i; k <= bad; ++k) {
                assert(mp[a[k]].back() == k);
                mp[a[k]].pop_back();
            }
            for (int x : updates) {
                if ((int)mp[x].size() >= 2) {
                    int j = mp[x][mp[x].size() - 2];
                    update(j, n - 1, -1);
                }
                if ((int)mp[x].size() >= 1) {
                    int j = mp[x][mp[x].size() - 1];
                    update(j, n - 1, 1);
                }
            }
            solve(bad + 1);
        };
        solve(0);
        cout << ans << "\n";
    }
}
