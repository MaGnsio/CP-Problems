/**
 *    author:  MaGnsi0
 *    created: 07.10.2022 16:38:05
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
        vector<int> f(26, 0);
        for (int i = 0; i < n; ++i) {
            f[s[i] - 'a']++;
        }
        string t = "";
        for (int i = 0; i < k; ++i) {
            int cnt = 0;
            char mex = 'a';
            for (int j = 0; j < 26; ++j) {
                if (cnt == n / k) {
                    break;
                }
                if (f[j]) {
                    mex++, cnt++, f[j]--;
                } else {
                    break;
                }
            }
            t += mex;
        }
        cout << t << "\n";
    }
}
