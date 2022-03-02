/**
 *    author:  MaGnsi0
 *    created: 10.02.2022 21:43:07
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string input;
    while(getline(cin, input)) {
        int a[3][3];
        stringstream sin(input);
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                sin >> a[i][j];
            }
        }
        int ans = INT_MAX;
        string s = "BCG", t;
        do {
            int cnt = 0;
            for (int i = 0; i < 3; ++i) {
                if (s[i] == 'B') {
                    cnt += a[i][1];
                    cnt += a[i][2];
                } else if (s[i] == 'C') {
                    cnt += a[i][0];
                    cnt += a[i][1];
                } else {
                    cnt += a[i][0];
                    cnt += a[i][2];
                }
            }
            if (cnt < ans) {
                ans = cnt;
                t = s;
            }
        } while (next_permutation(s.begin(), s.end()));
        cout << t << " " << ans << "\n";
    }
}
