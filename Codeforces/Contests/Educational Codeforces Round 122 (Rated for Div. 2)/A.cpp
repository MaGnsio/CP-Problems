/**
 *    author:  MaGnsi0
 *    created: 31.01.2022 23:26:29
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<int> a;
    for (int i = 7; i < 1000; i += 7) {
        a.push_back(i);
    }
    int T;
    cin >> T;
    while (T--) {
        int x;
        cin >> x;
        int res = 0, maxi = INT_MAX;
        for (int i = 0; i < (int)a.size(); ++i) {
            string s = to_string(x), t = to_string(a[i]);
            if (s.size() != t.size()) {
                continue;
            }
            int cnt = 0;
            for (int i = 0; i < (int)s.size(); ++i) {
                cnt += (s[i] != t[i]);
            }
            if (maxi > cnt) {
                maxi = cnt;
                res = a[i];
            }
        }
        cout << res << "\n";
    }
}
