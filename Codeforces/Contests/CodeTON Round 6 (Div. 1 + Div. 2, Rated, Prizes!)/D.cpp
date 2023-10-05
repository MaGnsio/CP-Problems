/**
 *    author:  MaGnsi0
 *    created: 19.09.2023 01:32:11
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
        vector<int> c(n);
        for (int i = 0; i < n; ++i) {
            cin >> c[i];
        }
        int k;
        cin >> k;
        for (int i = n - 2; i >= 0; --i) {
            c[i] = min(c[i], c[i + 1]);
        }
        int last_got = k;
        for (int i = 0; i < n; ++i) {
            int d = (c[i] - (i ? c[i - 1] : 0));
            last_got = (d == 0 ? last_got : min(last_got, k / d));
            k -= last_got * d;
            cout << last_got << " ";
        }
        cout << "\n";
    }
}
