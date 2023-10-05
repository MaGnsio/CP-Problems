/**
 *    author:  MaGnsi0
 *    created: 18/08/2021 16:27:53
**/
#include <bits/stdc++.h>
using namespace std;

int f(string n, string s) {
    int i, j, res = 0;
    for (i = 0, j = 0; i < n.size() && j < s.size(); ++i) {
        if (n[i] == s[j]) {
            j++;
        } else {
            res++;
        }
    }
    res += (n.size() - j) + (s.size() - i);
    return res;
}

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    while (T--) {
        int ans = INT_MAX;
        string n;
        cin >> n;
        for (int i = 0; i < 63; ++i) {
            ans = min(ans, f(n, to_string(1LL << i)));
        }
        cout << ans << "\n";
    }
}
