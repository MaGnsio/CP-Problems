/**
 *    author:  MaGnsi0
 *    created: 31.12.2023 18:46:29
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int Q; cin >> Q;
    set<int> all;
    multiset<int> diffs;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        all.insert(x);
    }
    for (int x : all) {
        auto it = all.upper_bound(x);
        if (it != all.end()) {
            diffs.insert(*it - x);
        }
    }
    cout << (n <= 2 ? 0 : *all.rbegin() - *all.begin() - *diffs.rbegin()) << "\n";
    while (Q--) {
        int t; cin >> t;
        int x; cin >> x;
        auto it1 = all.upper_bound(x);
        auto it2 = all.lower_bound(x);
        auto it3 = all.begin();
        auto it4 = all.end();
        if (t == 0) {
            if (it1 != it4) {
                diffs.erase(diffs.find(*it1 - x));
            }
            if (it3 != it2) {
                it2--;
                diffs.erase(diffs.find(x - *it2));
                if (it1 != it4) {
                    diffs.insert(*it1 - *it2);
                }
            }
            all.erase(x);
            n--;
        } else if (t == 1) {
            int prv = -1, next = -1;
            if (it3 != it2 && it1 != it4) {
                it2--;
                diffs.erase(diffs.find(*it1 - *it2));
                prv = *it2;
                next = *it1;
            } else if (it3 != it2) {
                it2--;
                prv = *it2;
            } else if (it1 != it4) {
                next = *it1;
            }
            if (prv != -1) {
                diffs.insert(x - prv);
            }
            if (next != -1) {
                diffs.insert(next - x);
            }
            all.insert(x);
            n++;
        }
        cout << (n <= 2 ? 0 : *all.rbegin() - *all.begin() - *diffs.rbegin()) << "\n";
    }
}
