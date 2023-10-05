/**
 *    author:  MaGnsi0
 *    created: 24.01.2022 22:24:41
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
        vector<string> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        bool ok = false;
        for (int i = 0; i < n; ++i) {
            if ((int)a[i].size() == 1) {
                ok = true;
                break;
            }
        }
        if (ok) {
            cout << "YES\n";
            continue;
        }
        multiset<string> b(a.begin(), a.end());
        for (int i = 0; i < n; ++i) {
            int m = (int)a[i].size();
            if (m == 2) {
                string x = a[i];
                reverse(x.begin(), x.end());
                if (b.count(x)) {
                    ok = true;
                    break;
                } else {
                    for (int j = 0; j < 26; ++j) {
                        string y = char('a' + j) + x;
                        if (b.count(y)) {
                            ok = true;
                            break;
                        }
                    }
                    if (ok) {
                        break;
                    } else {
                        b.erase(b.find(a[i]));
                    }
                }
            } else {
                string x = a[i], y = a[i];
                reverse(x.begin(), x.end());
                y.pop_back();
                reverse(y.begin(), y.end());
                if (b.count(x) || b.count(y)) {
                    ok = true;
                    break;
                } else {
                    b.erase(b.find(a[i]));
                }
            }
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
}
