/**
 *    author:  MaGnsi0
 *    created: 06.01.2023 16:43:20
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
        set<int> s1, s2;
        for (int i = 1; i <= n; ++i) {
            s1.insert(i);
            s2.insert(i);
        }
        bool ok = true;
        vector<int> p(n), q(n);
        for (int i = 0; i < n; ++i) {
            if (s1.count(a[i])) {
                p[i] = a[i];
                s1.erase(a[i]);
            } else if (s2.count(a[i])) {
                q[i] = a[i];
                s2.erase(a[i]);
            } else {
                ok = false;
                break;
            }
        }
        if (!ok) {
            cout << "NO\n";
            continue;
        }
        set<int> s3, s4;
        for (auto& x : s1) {
            s3.insert(-x);
        }
        for (auto& x : s2) {
            s4.insert(-x);
        }
        for (int i = 0; i < n; ++i) {
            if (p[i]) {
                auto it = s4.lower_bound(-p[i]);
                if (it == s4.end()) {
                    ok = false;
                    break;
                }
                q[i] = -(*it);
                s4.erase(it);
            } else {
                auto it = s3.lower_bound(-q[i]);
                if (it == s3.end()) {
                    ok = false;
                    break;
                }
                p[i] = -(*it);
                s3.erase(it);
            }
        }
        if (!ok) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        for (int i = 0; i < n; ++i) {
            cout << p[i] << " ";
        }
        cout << "\n";
        for (int i = 0; i < n; ++i) {
            cout << q[i] << " ";
        }
        cout << "\n";
    }
}
