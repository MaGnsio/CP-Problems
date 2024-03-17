/**
 *    author:  MaGnsi0
 *    created: 02.01.2024 18:48:38
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int ans = 0, empty = 0, all = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] == 1) {
                ans += empty == 0;
                empty = max(empty, 1);
                empty--, all++;
            } else {
                int males = all / 2;
                int females = all - all / 2;
                if (males) {
                    if ((females + 2) / 2 + males / 2 > (females + 1) / 2 + (males + 1) / 2) {
                        females++, males--;
                    }
                }
                int boxes1 = (males + 1) / 2;
                int boxes2 = (females + 1) / 2;
                empty = ans - boxes1 - boxes2;
            }
        }
        cout << ans << "\n";
    }
}
