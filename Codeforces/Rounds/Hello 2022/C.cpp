/**
 *    author:  MaGnsi0
 *    created: 03.01.2022 16:27:21
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
        auto ask = [](int x) {
            cout << "? " << x << endl;
            cin >> x;
            return x;
        };
        vector<int> a(n, -1);
        for (int i = 1; i <= n; ++i) {
            if (a[i - 1] != -1) {
                continue;
            }
            while (true) {//reset
                if (ask(i) == i) {
                    break;
                }
            }
            int prev = i, x;
            while (true) {
                x = ask(i);
                if (x == i) {
                    break;
                }
                a[prev - 1] = x;
                prev = x;
            }
            a[prev - 1] = x;
        }
        cout << "!";
        for (int i = 0; i < n; ++i) {
            cout << " " << a[i];
        }
        cout << endl;
    }
}
