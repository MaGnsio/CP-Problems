/**
 *    author:  MaGnsi0
 *    created: 25.02.2023 16:26:43
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
        string s;
        cin >> s;
        vector<int> bad;
        for (int i = 0; i < n / 2; ++i) {
            if (s[i] != s[n - i - 1]) {
                bad.push_back(i);
            }
        }
        if (bad.empty()) {
            cout << "YES\n";
        } else {
            int m = (int)bad.size();
            cout << (bad[m - 1] - bad[0] + 1 == m ? "YES" : "NO") << "\n";
        }
    }
}
