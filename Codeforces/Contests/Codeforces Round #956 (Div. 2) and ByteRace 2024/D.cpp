/**
 *    author:  MaGnsi0
 *    created: 07.07.2024 21:22:30
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        vector<int> sa = a, sb = b;
        sort(sa.begin(), sa.end());
        sort(sb.begin(), sb.end());
        if (sa != sb) {
            cout << "NO\n";
            continue;
        }
        for (int i = 0; i < n; ++i) {
            a[i] = lower_bound(sa.begin(), sa.end(), a[i]) - sa.begin();
            b[i] = lower_bound(sb.begin(), sb.end(), b[i]) - sb.begin();
        }
        int inva = n, invb = n;
        vector<bool> donea(n, false), doneb(n, false);
        for (int i = 0; i < n; ++i) {
            if (!donea[i]) {
                for (int j = i; !donea[j]; j = a[j]) {
                    donea[j] = true;
                }
                inva--;
            }
            if (!doneb[i]) {
                for (int j = i; !doneb[j]; j = b[j]) {
                    doneb[j] = true;
                }
                invb--;
            }
        }
        cout << ((inva & 1) == (invb & 1) ? "YES" : "NO") << "\n";
    }
}
