/**
 *    author:  MaGnsi0
 *    created: 08.04.2023 16:39:09
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    function<int(int, int)> ask = [&](int x, int y) {
        cout << "? " << x << " " << y << endl;
        int ans;
        cin >> ans;
        return ans;
    };
    function<void(int, int)> guess = [&](int x, int y) {
        cout << "! " << x << " " << y << endl;
    };
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        if (n == 1 && m == 1) {
            assert(ask(n, m) == 0);
            guess(n, m);
        } else if (n == 1) {
            int y = ask(1, 1) + 1;
            assert(ask(n, y) == 0);
            guess(n, y);
        } else if (m == 1) {
            int x = ask(1, 1) + 1;
            assert(ask(x, m) == 0);
            guess(x, m);
        } else if (n == m) {
            int ans1 = ask(1, 1);
            int ans2 = ask(n, m);
            if (ans1 + 1 == n - ans2) {
                int x = ans1 + 1;
                int y = n - ans2;
                assert(ask(x, y) == 0);
                guess(x, y);
            } else {
                int ans3 = (ans1 + 1 <= n && n - ans2 > 0 ? ask(ans1 + 1, n - ans2) : 1);
                if (ans3) {
                    int x = n - ans2;
                    int y = ans1 + 1;
                    guess(x, y);
                } else {
                    int x = ans1 + 1;
                    int y = n - ans2;
                    guess(x, y);
                }
            }
        } else {
            int ans1 = ask(1, 1);
            int ans2 = ask(n, m);
            if (ans1 + 1 == n - ans2) {
                int x = ans1 + 1;
                int y = ask(x, 1) + 1;
                guess(x, y);
            } else if (ans1 + 1 == m - ans2) {
                int y = ans1 + 1;
                int x = ask(1, y) + 1;
                guess(x, y);
            } else {
                int ans3 = (n - ans2 > 0 && ans1 + 1 <= m ? ask(n - ans2, ans1 + 1) : 2);
                if (ans3) {
                    int x = ans1 + 1;
                    int y = m - ans2;
                    guess(x, y);
                } else {
                    int x = n - ans2;
                    int y = ans1 + 1;
                    guess(x, y);
                }
            }
        }
    }
}
