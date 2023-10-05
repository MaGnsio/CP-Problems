/**
 *    author:  MaGnsi0
 *    created: 25.09.2023 05:31:43
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    function<int(int, int)> ask = [&](int c, int d) {
        cout << "? " << c << " " << d << endl;
        int res; cin >> res; return res;
    };
    function<void(int, int, int, int)> solve = [&](int bit, int a, int b, int sign) {
        if (bit == -1) {
            cout << "! " << a << " " << b << endl;
            return;
        }
        int sign1 = ask(a | (1 << bit), b);
        int sign2 = ask(a, b | (1 << bit));
        if (sign1 == 1 && sign2 == -1) {
            solve(bit - 1, a, b, sign);
        } else if (sign1 == -1 && sign2 == 1) {
            solve(bit - 1, a | (1 << bit), b | (1 << bit), sign);
        } else if (sign == 1) {
            solve(bit - 1, a | (1 << bit), b, sign1);
        } else {
            solve(bit - 1, a, b | (1 << bit), sign1);
        }
    };
    solve(29, 0, 0, ask(0, 0));
}
