/**
 *    author:  MaGnsi0
 *    created: 04.02.2023 09:18:34
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    function<int(int)> F = [&](int x) {
        string s = to_string(x);
        set<char> _s(s.begin(), s.end());
        return s.size() == _s.size();
    };
    int l, r, ans = 0;
    cin >> l >> r;
    for (int i = l; i <= r; ++i) {
        ans += F(i);
    }
    cout << ans;
}
