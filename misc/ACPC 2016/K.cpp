#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int g, c, e;
        cin >> g >> c >> e;
        g = (g == 1 ? 1 : (g == 2 ? 3 : 5));
        if (c >= e) {
            cout << 0;
        } else {
            cout << g * (e - c);
        }
        if (T) { cout << "\n"; }
    }
}
