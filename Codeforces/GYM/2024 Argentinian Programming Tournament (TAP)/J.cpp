/**
 *    author:  MaGnsi0
 *    created: 08.09.2024 17:24:14
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int x; cin >> x;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    if (n == 2) {
        if (a[0] + a[1] == x) {
            cout << "*";
        } else {
            cout << a[0] << " " << a[1];
        }
        return 0;
    }
    map<int, int> F;
    for (int i = 0; i < n; ++i) {
        F[a[i]]++;
    }
    sort(a.begin(), a.end());
    for (int i = 1; i < n; ++i) {
        if (a[i] + a[i - 1] != x) { continue; }
        if (a[i] == a[i - 1]) {
            int f = F[a[i]];
            if (n - f < f - 1) {
                cout << "*";
                return 0;
            }
            vector<int> b;
            for (int j = 0; j < n; ++j) {
                if (a[j] == a[i]) { continue; }
                if (F[a[i]]) { b.push_back(a[i]); F[a[i]]--; }
                b.push_back(a[j]);
            }
            if (F[a[i]]) { b.push_back(a[i]); F[a[i]]--; }
            vector<int> c = b;
            for (int j = 1; j < n; ++j) {
                if (b[j] + b[j - 1] == x) {
                    c.clear();
                    for (int k = 1; k < j; ++k) {
                        c.push_back(b[k]);
                    }
                    c.push_back(b[0]);
                    for (int k = j; k < n; ++k) {
                        c.push_back(b[k]);
                    }
                }
            }
            for (int j = 0; j < n; ++j) {
                cout << c[j] << " ";
            }
            return 0;
        }
        if (F[a[i]] + F[a[i - 1]] == n) {
            cout << "*";
            return 0;
        }
        if (a[0] != a[i - 1]) {
            reverse(a.begin(), a.begin() + i);
        } else {
            reverse(a.begin() + i, a.end());
        }
        for (int j = 0; j < n; ++j) {
            cout << a[j] << " ";
        }
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
}
