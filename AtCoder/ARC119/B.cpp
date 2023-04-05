/**
 *    author:  MaGnsi0
 *    created: 09.11.2022 22:11:26
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    if (count(s.begin(), s.end(), '1') != count(t.begin(), t.end(), '1')) {
        cout << -1;
        return 0;
    }
    vector<int> a, b;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') {
            a.push_back(i);
        }
        if (t[i] == '0') {
            b.push_back(i);
        }
    }
    int ans = 0;
    for (int i = 0; i < (int)a.size(); ++i) {
        ans += a[i] != b[i];
    }
    cout << ans;
}
