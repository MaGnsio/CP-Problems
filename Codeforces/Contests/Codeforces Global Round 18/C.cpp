/**
 *    author:  MaGnsi0
 *    created: 01.01.2022 23:07:40
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        string s, t;
        cin >> n >> s >> t;
        int res = INT_MAX;
        if (count(s.begin(), s.end(), '1') == count(t.begin(), t.end(), '1')) {
            res = 0;
            for (int i = 0; i < n; ++i) {
                res += (s[i] != t[i]);
            }
        }
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1' && t[i] == '1') {
                for (int j = 0; j < n; ++j) {
                    if (j != i) {
                        s[j] = (s[j] == '1' ? '0' : '1');
                    }
                }
                int cnt = INT_MAX;
                if (count(s.begin(), s.end(), '1') == count(t.begin(), t.end(), '1')) {
                    cnt = 1;
                    for (int j = 0; j < n; ++j) {
                        cnt += (s[j] != t[j]);
                    }
                }
                res = min(res, cnt);
                break;
            }
        }
        cout << (res == INT_MAX ? -1 : res) << "\n";
    }
}
