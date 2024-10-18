/**
 *    author:  MaGnsi0
 *    created: 18.10.2024 19:27:19
**/
#include <bits/stdc++.h>

using namespace std;

const int OO = 1e5 + 5;

int solve(string s) {
    int n = (int)s.size();
    vector<int> pre(n);
    for (int i = n - 1; i >= 0; --i) {
        pre[i] = (s[i] == 'L' || s[i] == '?' ? -1 : +1);
    }
    for (int i = 1; i < n; ++i) {
        pre[i] += pre[i - 1];
    }
    for (int i = n - 2; i >= 0; --i) {
        pre[i] = min(pre[i], pre[i + 1]);
    }
    int ans = 0, Q = 0, val = 0, minp = 0, maxp = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '?') {
            Q++;
        } else {
            val += (s[i] == 'L' ? -1 : +1);
        }
        minp = min(minp, val + Q);
        maxp = max(maxp, val + Q);
        ans = max(ans, maxp - min(minp, (i + 1 < n ? pre[i + 1] + 2 * Q : OO)));
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s; cin >> s;
    int ans = solve(s);
    for (char& c : s) {
        if (c == 'L') {
            c = 'R';
        } else if (c == 'R') {
            c = 'L';
        }
    }
    ans = max(ans, solve(s));
    cout << ans;
}
