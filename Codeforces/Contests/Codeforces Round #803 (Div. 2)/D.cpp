/**
 *    author:  MaGnsi0
 *    created: 28.06.2022 16:34:06
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
        function<int(int, int)> ask = [](int l, int r) {
            cout << "? " << l + 1 << " " << r + 1 << endl;
            int cnt = 0;
            vector<int> a(r - l + 1);
            for (int i = 0; i < r - l + 1; ++i) {
                cin >> a[i];
                cnt += (l + 1 <= a[i] && a[i] <= r + 1);
            }
            return cnt;
        };
        int l = 0, r = n - 1;
        while (l < r) {
            int m = (l + r) / 2;
            if (ask(l, m) & 1) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        cout << "! " << l + 1 << endl;
    }
}
