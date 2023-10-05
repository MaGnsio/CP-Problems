/**
 *    author:  MaGnsi0
 *    created: 24.08.2023 19:08:42
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            b[i] = a[i];
        }
        sort(b.begin(), b.end());
        multiset<int> S, D;
        for (int i = 0; i < n; ++i) {
            S.insert(a[i]);
        }
        for (int i = 1; i < n; ++i) {
            D.insert(b[i] - b[i - 1]);
        }
        D.insert(0);
        int Q; cin >> Q;
        while (Q--) {
            int j, x;
            cin >> j >> x;
            j--;
            //remove old
            {
                S.erase(S.find(a[j]));
                if (S.find(a[j]) == S.end()) {
                    int nxt = (S.upper_bound(a[j]) == S.end() ? -1 : *S.upper_bound(a[j]));
                    int prv = (S.empty() || S.upper_bound(a[j]) == S.begin() ? -1 : *prev(S.upper_bound(a[j])));
                    if (nxt != -1 && D.find(nxt - a[j]) != D.end()) {
                        D.erase(D.find(nxt - a[j]));
                    }
                    if (prv != -1 && D.find(a[j] - prv) != D.end()) {
                        D.erase(D.find(a[j] - prv));
                    }
                    if (nxt != -1 && prv != -1) {
                        D.insert(nxt - prv);
                    }
                }
            }
            a[j] = x;
            //add new
            {
                if (S.find(a[j]) == S.end()) {
                    int nxt = (S.upper_bound(a[j]) == S.end() ? -1 : *S.upper_bound(a[j]));
                    int prv = (S.empty() || S.upper_bound(a[j]) == S.begin() ? -1 : *prev(S.upper_bound(a[j])));
                    if (nxt != -1) {
                        D.insert(nxt - a[j]);
                    }
                    if (prv != -1) {
                        D.insert(a[j] - prv);
                    }
                    if (nxt != -1 && prv != -1 && D.find(nxt - prv) != D.end()) {
                        D.erase(D.find(nxt - prv));
                    }
                }
                S.insert(a[j]);
            }
            cout << *S.rbegin() + *D.rbegin() << " ";
        }
        cout << "\n";
    }
}
