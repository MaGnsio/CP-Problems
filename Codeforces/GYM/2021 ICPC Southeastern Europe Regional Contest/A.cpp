/**
 *    author:  MaGnsi0
 *    created: 25.03.2022 16:38:42
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    string s, t;
    cin >> n >> s >> t;
    int cur_pre = 0;
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] > t[i]) {
            cur_pre = 0;
        } else if (s[i] < t[i]) {
            ans += 1LL * (cur_pre + 1) * (n - i);
            cur_pre = 0;
        } else {
            cur_pre++;
        }
    }
    cout << ans;
}
