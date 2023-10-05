/**
 *    author:  MaGnsi0
 *    created: 13.09.2023 16:42:40
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int k;
    string s;
    cin >> s >> k;
    int n = (int)s.size();
    vector<string> a(k, "");
    for (int i = 0; i < n; ++i) {
        a[i % k] += s[i];
    }
    for (int i = 0; i < k; ++i) {
        sort(a[i].begin(), a[i].end());
    }
    string ans = "";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; ++j) {
            if ((int)a[j].size() <= i) {
                break;
            }
            ans += a[j][i];
        }
    }
    cout << ans;
}
