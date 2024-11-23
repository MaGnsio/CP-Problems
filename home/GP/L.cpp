/**
 *    author:  MaGnsi0
 *    created: 23.11.2024 11:05:23
**/
#include <bits/stdc++.h>

using namespace std;

bool contains(string s, string t) {
    int n = (int)s.size();
    int m = (int)t.size();
    for (int i = 0; i + m - 1 < n; ++i) {
        if (s.substr(i, m) == t) {
            return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        if (contains(s, "rest")) {
            a[i] = "\U0001F60E";
        } else if (contains(s, "leg")) {
            a[i] = "\U0001f9b5";
        } else {
            a[i] = "\U0001f4aa";
        }
    }
    for (int d = 1; d <= 31; ++d) {
        if (d != 1 && d % 7 == 1) {
            cout << "\n";
        }
        if (d % 7 == 1) {
            cout << (d / 7) + 1 << " ";
        }
        cout << a[(d - 1) % n];
    }
}

