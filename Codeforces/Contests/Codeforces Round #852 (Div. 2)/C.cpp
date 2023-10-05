/**
 *    author:  MaGnsi0
 *    created: 12.02.2023 10:48:49
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        set<int> s(a.begin(), a.end());
        int L = 0, R = n - 1, ansL = -1, ansR = -1;
        while (L < R) {
            int mine = *s.begin();
            int maxe = *s.rbegin();
            if (mine != a[L] && mine != a[R] && maxe != a[L] && maxe != a[R]) {
                ansL = L, ansR = R;
                break;
            }
            if (mine == a[L] || maxe == a[L]) {
                s.erase(a[L]);
                L++;
            }
            if (mine == a[R] || maxe == a[R]) {
                s.erase(a[R]);
                R--;
            }
        }
        if (ansL == -1) {
            cout << -1 << "\n";
        } else {
            cout << ansL + 1 << " " << ansR + 1 << "\n";
        }
    }
}
