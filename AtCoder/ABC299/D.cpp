/**
 *    author:  MaGnsi0
 *    created: 22.04.2023 15:06:24
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    function<int(int)> ask = [&](int j) {
        cout << "? " << j + 1 << endl;
        int x;
        cin >> x;
        return x;
    };
    int n;
    cin >> n;
    int l = 0, r = n - 1;
    while (r - l + 1 > 2) {
        int m = (l + r) / 2;
        int x = ask(m);
        if (x == 0) {
            l = m;
        } else {
            r = m;
        }
    }
    cout << "! " << l + 1 << endl;
}
