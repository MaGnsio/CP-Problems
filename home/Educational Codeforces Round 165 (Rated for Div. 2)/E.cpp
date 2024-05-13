/**
 *    author:  MaGnsi0
 *    created: 13.05.2024 15:46:46
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
            if (from > to) { return OO; }
            return query_(0, 0, n - 1, from, to);
        };
        update(0, n - 1, -OO);
        int ans = 0;
        map<int, vector<int>> pos;
        for (int i = 0, bad = 0; i < n; ++i) {
            int x = a[i];
            pos[x].push_back(i);
            int m = (int)pos[x].size();
            if (m > 0) { update(bad, pos[x][m - 1], +1); }
            if (m > 1) { update(bad, pos[x][m - 2], -2); }
            if (m > 2) { update(bad, pos[x][m - 3], +1); }
            if (query(bad, i) == 0) { bad = i + 1, ans++; }
        }
        cout << ans << "\n";
    }
}
