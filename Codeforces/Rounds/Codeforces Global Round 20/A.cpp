/**
 *    author:  MaGnsi0
 *    created: 23.04.2022 15:57:36
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
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int cuts = 0;
        for (int i = 0; i < n; ++i) {
            cuts += a[i] - 1;
        }
        cout << (cuts & 1 ? "errorgorn" : "maomao90") << "\n";
    }
}
