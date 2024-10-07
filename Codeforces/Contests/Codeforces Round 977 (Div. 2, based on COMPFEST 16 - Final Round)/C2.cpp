/**
 *    author:  MaGnsi0
 *    created: 07.10.2024 20:23:49
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int m; cin >> m;
        int Q; cin >> Q;
        vector<int> a(n), pos(n), b(m);
        for (int i = 0; i < n; ++i) {
            cin >> a[i]; a[i]--; pos[a[i]] = i;
        }
        for (int i = 0; i < m; ++i) {
            cin >> b[i]; b[i]--;
        }
        vector<set<int>> occur(n);
        for (int i = 0; i < m; ++i) {
            occur[b[i]].insert(i);
        }
        set<pair<int, int>> first_occur;
        for (int i = 0; i < n; ++i) {
            if (occur[i].empty()) { continue; }
            first_occur.emplace(*occur[i].begin(), i);
        }
        first_occur.emplace(-1, -1);
        first_occur.emplace(m, n);
        function<bool(int)> check = [&](int i) {
            if (occur[i].empty()) { return true; }
            int j = pos[i];
            int l1 = (j ? a[j - 1] : -1);
            auto it = first_occur.lower_bound(make_pair(*occur[i].begin(), i));
            int l2 = prev(it) -> second;
            return (l1 == l2);
        };
        function<set<int>(int)> get_changes_element = [&](int x) {
            set<int> changes = {x};
            if (!occur[x].empty()) {
                auto it = first_occur.lower_bound(make_pair(*occur[x].begin(), x));
                changes.emplace(prev(it) -> second);
                changes.emplace(x);
                changes.emplace(next(it) -> second);
            }
            return changes;
        };
        function<set<int>(int)> get_changes_index = [&](int i) {
            set<int> changes = { b[i] };
            {
                int j = pos[b[i]];
                int l1 = (j ? a[j - 1] : -1);
                int r1 = (j + 1 < n ? a[j + 1] : n);
                changes.emplace(l1);
                changes.emplace(b[i]);
                changes.emplace(r1);
            }
            {
                auto it1 = first_occur.lower_bound(make_pair(i, 0)); 
                auto it2 = first_occur.lower_bound(make_pair(i + 1, 0));
                changes.emplace(prev(it1) -> second);
                changes.emplace(it2 -> second);
            }
            return changes;
        };
        int good = 0;
        for (int i = 0; i < n; ++i) {
            good += check(i);
        }
        cout << (good == n ? "YA" : "TIDAK") << "\n";
        while (Q--) {
            int j; cin >> j; j--;
            int x; cin >> x; x--;
            set<int> changes;
            for (int i : get_changes_element(x)) {
                changes.insert(i);
            }
            for (int i : get_changes_element(b[j])) {
                changes.insert(i);
            }
            for (int i : get_changes_index(j)) {
                changes.insert(i);
            }
            if (occur[b[j]].upper_bound(j) != occur[b[j]].end()) {
                for (int i : get_changes_index(*occur[b[j]].upper_bound(j))) {
                    changes.insert(i);
                }
            }
            {
                changes.erase(-1);
                changes.erase(n);
                changes.emplace(x);
            }
            for (int i : changes) {
                good -= check(i);
            }
            first_occur.erase(make_pair(*occur[b[j]].begin(), b[j]));
            if (!occur[x].empty()) {
                first_occur.erase(make_pair(*occur[x].begin(), x));
            }
            occur[b[j]].erase(j);
            occur[x].insert(j);
            if (!occur[b[j]].empty()) {
                first_occur.emplace(*occur[b[j]].begin(), b[j]);
            }
            first_occur.emplace(*occur[x].begin(), x);
            b[j] = x;
            for (int i : changes) {
                good += check(i);
            }
            cout << (good == n ? "YA" : "TIDAK") << "\n";
        }
    }
}
