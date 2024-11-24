/**
 *    author:  MaGnsi0
 *    created: 24.11.2024 22:17:49
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i]; a[i]--;
    }
    int ans = 0;
    for (int j = 0; j < 2; ++j) {
        vector<bool> done(n, false);
        for (int s = -1, i = j; i + 1 < n; i += 2) {
            if (a[i] != a[i + 1]) {
                if (s == -1) { continue; }
                while (s < i) {
                    done[a[s]] = false;
                    s += 2;
                }
                s = -1;
            } else if (done[a[i]] == false) {
                done[a[i]] = true;
                s = (s == -1 ? i : s);
            } else {
                while (s < i) {
                    done[a[s]] = false;
                    if (a[s] == a[i]) { s += 2; break; }
                    s += 2;
                }
                done[a[i]] = true;
            }
            if (s != -1) { ans = max(ans, i - s + 2); }
        }
    }
    cout << ans;
}
