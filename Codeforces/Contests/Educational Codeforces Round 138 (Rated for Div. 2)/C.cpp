/**
 *    author:  MaGnsi0
 *    created: 20.10.2022 16:45:22
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int k = n; k >= 0; --k) {
            bool won = true;
            multiset<int> s;
            for (int i = 0; i < n; ++i) {
                s.insert(-a[i]);
            }
            for (int j = k; j > 0; --j) {
                auto it = s.lower_bound(-j);
                if (it == s.end()) {
                    won = false;
                    break;
                }
                s.erase(it);
                if (!s.empty()) {
                    int x = *s.rbegin();
                    s.erase(s.find(x));
                }
            }
            if (won) {
                cout << k << "\n";
                break;
            }
        }
    }
}
