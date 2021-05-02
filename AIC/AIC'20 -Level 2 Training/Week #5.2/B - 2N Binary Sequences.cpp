//https://vjudge.net/contest/435128#problem/B
#include <bits/stdc++.h>
using namespace std;

void solve(int n, int cnt = 0, string s = "") {
    if (cnt == 2 * n) {
        if (count(s.begin(), s.begin() + n, '0') == count(s.begin() + n, s.end(), '0')) {
            cout << s << "\n";
        }
        return;
    }
    if (cnt >= n) {
        if (count(s.begin(), s.begin() + n, '0') < count(s.begin() + n, s.end(), '0')) {
            return;
        }
        if (count(s.begin(), s.begin() + n, '1') < count(s.begin() + n, s.end(), '1')) {
            return;
        }
    }
    solve(n, cnt + 1, s + "0");
    solve(n, cnt + 1, s + "1");
}

int main () {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        solve(n);
    }
}

