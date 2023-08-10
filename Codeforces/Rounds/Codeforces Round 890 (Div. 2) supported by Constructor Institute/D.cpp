/**
 *    author:  MaGnsi0
 *    created: 05.08.2023 22:52:43
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
        function<int(int, int)> ask = [&](int l, int r) {
            if (l == r) { return 0; }
            cout << "? " << l + 1 << " " << r + 1 << endl;
            int inv; cin >> inv; return inv;
        };
        function<int(int, int)> max = [&](int low, int high) {
            if (high - low + 1 == 1) {
                return low;
            }
            if (high - low + 1 == 2) {
                return high - ask(low, high);
            }
            int mid = (low + high) / 2;
            int x = max(low, mid);
            int y = max(mid + 1, high);
            if (ask(x, y - 1) == ask(x, y)) {
                return y;
            } else {
                return x;
            }
        };
        int ans = max(0, n - 1);
        cout << "! " << ans + 1 << endl;
    }
}
