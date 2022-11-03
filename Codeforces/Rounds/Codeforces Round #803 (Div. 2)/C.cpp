/**
 *    author:  MaGnsi0
 *    created: 28.06.2022 16:34:06
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
        sort(a.begin(), a.end());
        vector<int> pos, neg;
        for (int i = 0; i < n; ++i) {
            if (a[i] > 0) {
                pos.push_back(a[i]);
            } else if (a[i] < 0) {
                neg.push_back(a[i]);
            }
        }
        if ((int)pos.size() > 2 || (int)neg.size() > 2) {
            cout << "NO\n";
            continue;
        }
        for (int i = 0; i < (int)neg.size(); ++i) {
            pos.push_back(neg[i]);
        }
        if (count(a.begin(), a.end(), 0)) {
            pos.push_back(0);
        }
        bool ok = true;
        for (int i = 0; i < (int)pos.size(); ++i) {
            for (int j = i + 1; j < (int)pos.size(); ++j) {
                for (int k = j + 1; k < (int)pos.size(); ++k) {
                    int64_t sum = int64_t(pos[i]) + pos[j] + pos[k];
                    bool have = false;
                    for (int l = 0; l < (int)pos.size(); ++l) {
                        have |= bool(sum == pos[l]);
                    }
                    ok &= have;
                }
            }
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
}
