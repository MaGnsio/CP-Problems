/**
 *    author:  MaGnsi0
 *    created: 15.07.2024 21:50:28
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int64_t n; cin >> n;
        vector<int64_t> ans;
        for (int b = 62; b >= 0; --b) {
            if (n >> b & 1) {
                if (n == (1LL << b)) { continue; }
                ans.push_back(n ^ (1LL << b));
            }
        }
        ans.push_back(n);
        cout <<  (int)ans.size() << "\n";
        for (int64_t x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
}
