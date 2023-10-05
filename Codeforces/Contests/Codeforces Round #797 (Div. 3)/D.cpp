/**
 *    author:  MaGnsi0
 *    created: 07.06.2022 16:34:07
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        string s;
        cin >> n >> k >> s;
        int ans = 0, cntW = 0;
        for (int i = 0; i < k; ++i) {
            cntW += (s[i] == 'W');
        }
        ans = cntW;
        for (int i = k; i < n; ++i) {
            cntW -= (s[i - k] == 'W');
            cntW += (s[i] == 'W');
            ans = min(ans, cntW);
        }
        cout << ans << "\n";
    }
}
