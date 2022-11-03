/**
 *    author:  MaGnsi0
 *    created: 12.09.2022 16:33:16
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    function<int64_t(int64_t, int64_t)> ask = [&](int64_t u, int64_t v) {
        cout << "? " << u << " " << v << endl;
        int64_t d;
        cin >> d;
        return d;
    };
    for (int i = 3; i <= 28; ++i) {
        int64_t d1 = ask(1, i);
        if (d1 == -1) {
            cout << "! " << i - 1 << endl;
            return 0;
        }
        int64_t d2 = ask(i, 1);
        if (d1 != d2) {
            cout << "! " << d1 + d2 << endl;
        }
    }
}
