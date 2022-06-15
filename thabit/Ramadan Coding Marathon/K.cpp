/**
 *    author:  MaGnsi0
 *    created: 21.04.2022 09:59:59
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, x, y, z;
    cin >> n >> x >> y >> z;
    string a, b, s;
    cin >> a >> b >> s;
    vector<char> ans(n);
    for (int i = 0; i < n; ++i) {
        if (a[i] > b[i]) {
            swap(a[i], b[i]);
        }
    }
    for (int i = 0; i < n; ++i) {
        if (a[i] == '0' && b[i] == '0' && s[i] == '1') {
            cout << "NO";
            return 0;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (a[i] == '0' && b[i] == '1' && s[i] == '0') {
            if (x) {
                ans[i] = '&';
                x--;
            } else {
                cout << "NO";
                return 0;
            }
        }
        if (a[i] == '1' && b[i] == '1' && s[i] == '0') {
            if (z) {
                ans[i] = '^';
                z--;
            } else {
                cout << "NO";
                return 0;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (a[i] == '0' && b[i] == '1' && s[i] == '1') {
            if (z) {
                ans[i] = '^';
                z--;
            } else if (y) {
                ans[i] = '|';
                y--;
            } else {
                cout << "NO";
                return 0;
            }
        }
        if (a[i] == '1' && b[i] == '1' && s[i] == '1') {
            if (x) {
                ans[i] = '&';
                x--;
            } else if (y) {
                ans[i] = '|';
                y--;
            } else {
                cout << "NO";
                return 0;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (a[i] == '0' && b[i] == '0' && s[i] == '0') {
            if (x) {
                ans[i] = '&';
                x--;
            } else if (y) {
                ans[i] = '|';
                y--;
            } else if (z) {
                ans[i] = '^';
                z--;
            } else {
                cout << "NO";
                return 0;
            }
        }
    }
    cout << "YES\n";
    for (int i = 0; i < n; ++i) {
        cout << ans[i];
    }
}
