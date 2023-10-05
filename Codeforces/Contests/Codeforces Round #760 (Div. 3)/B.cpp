/**
 *    author:  MaGnsi0
 *    created: 14.12.2021 22:04:29
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
        vector<string> a(n - 2);
        for (int i = 0; i < n - 2; ++i) {
            cin >> a[i];
        }
        string s = a[0];
        for (int i = 1; i < n - 2; ++i) {
            if (a[i][0] == a[i - 1][1]) {
                s += a[i][1];
            } else {
                s += a[i];
            }
        }
        if ((int)s.size() != n) {
            s.pop_back();
            s += a[n - 3];
        }
        assert((int)s.size() == n);
        cout << s << "\n";
    }
}
