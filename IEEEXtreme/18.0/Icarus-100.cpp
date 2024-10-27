/**
 *    author:  MaGnsi0
 *    created: 26.10.2024 16:10:06
**/
#include <bits/stdc++.h>

using namespace std;

void solve1(string s) {
    int n = 2 * (int)s.size();
    if (n == 2) {
        if (s[0] == 'U') {
            cout << 2 << " " << 1 << " " << 2 << "\n";
            cout << 0 << " " << 2 << "\n";
            cout << 0 << " " << 0 << "\n";
        } else {
            cout << 2 << " " << 2 << " " << 1 << "\n";
            cout << 0 << " " << 2 << "\n";
            cout << 0 << " " << 0 << "\n";
        }
        exit(0);
    }
    cout << n << " " << n << " " << 2 << "\n";
    cout << 2 << " " << 3 << "\n";
    for (int i = 2; i <= n; ++i) {
        if (i == 2) {
            cout << 0 << " " << (i + 2 <= n ? i + 2 : 0) << "\n";
        } else if (i != 3) {
            cout << 0 << " " << (i + 1 <= n ? i + 1 : 0) << "\n";
        } else {
            cout << 0 << " " << 0 << "\n";
        }
    }
}

void solve2(string s) {
    int n = 2 * (int)s.size();
    if (n == 2) {
        assert(0);
        if (s[0] == 'U') {
            cout << 2 << " " << 1 << " " << 2 << "\n";
            cout << 0 << " " << 2 << "\n";
            cout << 0 << " " << 0 << "\n";
        } else {
            cout << 2 << " " << 2 << " " << 1 << "\n";
            cout << 0 << " " << 2 << "\n";
            cout << 0 << " " << 0 << "\n";
        }
        exit(0);
    }
    int c1 = count(s.begin(), s.end(), 'L');
    int c2 = count(s.begin(), s.end(), 'R');
    cout << n << " " << (n & 1 ? n : n - 1) << " " << (n & 1 ? n - 1 : n) << "\n";
    cout << 2 << " " << 3 << "\n";
    for (int i = 2; i <= n; ++i) {
        if (i & 1) {
            if (c1 <= c2) {
                cout << 0 << " " << (i + 2 <= n ? i + 2 : 0) << "\n";
            } else {
                cout << (i + 2 <= n ? i + 2 : 0) << " " << 0 << "\n";
            }
        } else {
            if (c1 <= c2) {
                cout << (i + 2 <= n ? i + 2 : 0) << " " << 0 << "\n";
            } else {
                cout << 0 << " " << (i + 2 <= n ? i + 2 : 0) << "\n";
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s; cin >> s;
    solve2(s);
}
