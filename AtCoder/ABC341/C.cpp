/**
 *    author:  MaGnsi0
 *    created: 17.02.2024 14:10:27
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int h; cin >> h;
    int w; cin >> w;
    int n; cin >> n;
    string s; cin >> s;
    vector<string> a(h);
    for (int i = 0; i < h; ++i) {
        cin >> a[i];
    }
    int ans = 0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (a[i][j] == '#') { continue; }
            bool good = true;
            for (int k = 0, x = i, y = j; k < n; ++k) {
                x += (s[k] == 'D') - (s[k] == 'U');
                y += (s[k] == 'R') - (s[k] == 'L');
                good = good && a[x][y] == '.';
                if (!good) { break; }
            }
            ans += good;
        }
    }
    cout << ans;
}
