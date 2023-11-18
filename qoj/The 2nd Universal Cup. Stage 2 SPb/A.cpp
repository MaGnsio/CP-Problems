/**
 *    author:  MaGnsi0
 *    created: 14.10.2023 11:09:11
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    string s;
    cin >> n >> s;
    vector<set<int>> a(4);
    for (int i = 0; i < n; ++i) {
        if (s[i] == 's') { a[0].insert(i); }
        if (s[i] == 'p') { a[1].insert(i); }
        if (s[i] == 'b') { a[2].insert(i); }
        if (s[i] == 'u') { a[3].insert(i); }
    }
    int ans = 10 * n;
    for (int x : a[0]) {
        vector<int> b(5);
        b[0] = x;
        if (a[1].lower_bound(b[0]) == a[1].end()) { break; }
        b[1] = *a[1].lower_bound(b[0]);
        if (a[2].lower_bound(b[1]) == a[2].end()) { break; }
        b[2] = *a[2].lower_bound(b[1]);
        if (a[0].lower_bound(b[2]) == a[0].end()) { break; }
        b[3] = *a[0].lower_bound(b[2]);
        if (a[3].lower_bound(b[3]) == a[3].end()) { break; }
        b[4] = *a[3].lower_bound(b[3]);
        for (int i = 0; i < 5; ++i) {
            int val = 0;
            for (int j = i - 1, k = 1; j >= 0; --j, ++k) {
                val += (b[i] - k) - b[j];
            }
            for (int j = i + 1, k = 1; j < 5; ++j, ++k) {
                val += b[j] - (b[i] + k);
            }
            ans = min(ans, val);
        }
    }
    cout << ans << "\n";
}
