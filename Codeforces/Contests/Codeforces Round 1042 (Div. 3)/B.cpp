/**
 *    author:  MaGnsi0
 *    created: 10.08.2025 17:44:18
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> ans;
        for (int i = 0; i < n / 2; ++i) {
            ans.push_back(-1);
            ans.push_back(+3);

        }
        if (n % 2 == 0) {
            ans.back() = 2;
        } else {
            ans.push_back(-1);
        }
        for (int x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
}
