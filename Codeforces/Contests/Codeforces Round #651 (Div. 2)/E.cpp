/**
 *    author:  MaGnsi0
 *    created: 21.04.2022 03:29:15
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    string s, t;
    cin >> n >> s >> t;
    if (count(s.begin(), s.end(), '0') != count(t.begin(), t.end(), '0')) {
        cout << -1;
        return 0;
    }
    vector<set<int>> a(2);
    for (int i = 0; i < n; ++i) {
        if (s[i] != t[i]) {
            a[s[i] - '0'].insert(i);
        }
    }
    auto make_subsequence = [&]() {
        int last, j;
        if (a[1].empty() || (!a[0].empty() && *a[0].begin() < *a[1].begin())) {
            last = *a[0].begin();
            a[0].erase(a[0].begin());
            j = 1;
        } else {
            last = *a[1].begin();
            a[1].erase(a[1].begin());
            j = 0;
        }
        while (true) {
            auto it = a[j].lower_bound(last);
            if (it == a[j].end()) {
                return;
            }
            last = *it;
            a[j].erase(it);
            j ^= 1;
        }
    };
    int ans = 0;
    while (!a[0].empty() || !a[1].empty()) {
        make_subsequence();
        ans++;
    }
    cout << ans;
}
