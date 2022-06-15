/**
 *    author:  MaGnsi0
 *    created: 01.06.2022 15:52:32
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
        int ans = 0, last_one = -1, first_one = -1;
        for (int i = 0; i < n - 1; ++i) {
            if (s[i] == '1') {
                last_one = i;
                if (i && first_one == -1) {
                    first_one = i;
                }
            }
            ans += (s[i] == '0' ? (s[i + 1] == '0' ? 0 : 1) : (s[i + 1] == '0' ? 10 : 11));
        }
        bool ok = false;
        if (last_one != -1 && s[n - 1] != '1' && n - 1 - last_one <= k) {
            ans -= 10 - (last_one == 0);
            k -= (n - 1 - last_one);
            ok = true;
        }
        if (first_one != -1 && (first_one != last_one || !ok) && s[0] != '1' && first_one <= k) {
            ans--;
            k -= first_one;
        }
        cout << ans << "\n";
    }
}
