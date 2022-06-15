/**
 *    author:  MaGnsi0
 *    created: 23.04.2022 15:57:39
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    function<int(int)> ask = [](int w) {
        int h;
        cout << "? " << w << endl;
        cin >> h;
        return h;
    };
    int l = 1, r = 1e9, length;
    while (l <= r) {
        int m = l + (r - l) / 2;
        int h = ask(m);
        if (h == 0) {
            l = m + 1;
        } else if (h == 1) {
            length = m;
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    int ans = length;
    for (int i = 1; i < n; ++i) {
        int x = (length / (i + 1)) * ask(length / (i + 1));
        if (x) {
            ans = min(ans, x);
        }
    }
    cout << "! " << ans << endl;
}
