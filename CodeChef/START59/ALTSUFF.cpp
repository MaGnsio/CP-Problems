/**
 *    author:  MaGnsi0
 *    created: 05.10.2022 17:15:34
**/
#include <bits/stdc++.h>

using namespace std;

const int OO = 5e6;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        string s;
        cin >> n >> k >> s;
        if (count(s.begin(), s.end(), '0') == n) {
            cout << s << "\n";
            continue;
        }
        if (count(s.begin(), s.end(), '1') == n) {
            cout << string(n, '0') << "\n";
            continue;
        }
        vector<int> a(n), b(n), c(n), d(n);
        a[0] = OO, b[n - 1] = OO;
        for (int i = 1; i < n; ++i) {
            a[i] = (s[i - 1] == '1' ? i - 1 : a[i - 1]);
            b[n - i - 1] = (s[n - i] == '1' ? n - i : b[n - i]);
        }
        c[0] = OO, d[n - 1] = OO;
        for (int i = 1; i < n; ++i) {
            c[i] = (s[i - 1] == '0' ? i - 1 : c[i - 1]);
            d[n - i - 1] = (s[n - i] == '0' ? n - i : d[n - i]);
        }
        string t = s;
        for (int i = 0; i < n; ++i) {
            int x;
            if (s[i] == '0') {
                x = min(abs(i - a[i]), abs(b[i] - i));
            } else {
                x = min(abs(i - c[i]), abs(d[i] - i));
            }
            if (s[i] == '0') {
                if (x % 2 == k % 2 && x <= k) {
                    t[i] = (s[i] == '1' ? '0' : '1');
                }
            } else {
                if ((k < x) || (x % 2 == k % 2)) {
                    t[i] = (s[i] == '1' ? '0' : '1');
                }
            }
        }
        cout << t << "\n";
    }
}
