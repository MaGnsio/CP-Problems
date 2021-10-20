/**
 *    author:  MaGnsi0
 *    created: 18/09/2021 19:02:10
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int n;
        string s;
        cin >> n >> s;
        vector<long long> pre(n, INT_MAX), suf(n, INT_MAX);
        for (int i = 0, cur = -1; i < n; ++i) {
            if (s[i] == '1') {
                cur = 0;
            }
            if (cur == -1) {
                continue;
            }
            pre[i] = cur;
            cur++;
        }
        for (int i = n - 1, cur = -1; i >= 0; --i) {
            if (s[i] == '1') {
                cur = 0;
            }
            if (cur == -1) {
                continue;
            }
            suf[i] = cur;
            cur++;
        }
        long long sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += min(pre[i], suf[i]);
        }
        cout << "Case #" << t << ": " << sum << "\n";
    }
}
