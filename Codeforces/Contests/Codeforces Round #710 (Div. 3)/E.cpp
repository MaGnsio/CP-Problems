/**
 *    author:  MaGnsi0
 *    created: 01.11.2022 19:38:32
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
        vector<int> b(n), c(n);
        b[0] = c[0] = a[0];
        set<int> s1, s2;
        for (int i = 1; i < n; ++i) {
            s1.insert(i);
            s2.insert(-i);
        }
        s1.erase(a[0]);
        s2.erase(-a[0]);
        for (int i = 1; i < n; ++i) {
            if (a[i] != a[i - 1]) {
                b[i] = c[i] = a[i];
                s1.erase(a[i]);
                s2.erase(-a[i]);
            } else {
                b[i] = *s1.begin();
                s1.erase(*s1.begin());
                int x = *s2.lower_bound(-a[i]);
                c[i] = -x;
                s2.erase(x);
            }
        }
        for (int i = 0; i < n; ++i) {
            cout << b[i] << " ";
        }
        cout << "\n";
        for (int i = 0; i < n; ++i) {
            cout << c[i] << " ";
        }
        cout << "\n";
    }
}
