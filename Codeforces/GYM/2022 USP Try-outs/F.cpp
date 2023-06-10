/**
 *    author:  MaGnsi0
 *    created: 02.06.2023 22:52:46
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    int L = 1, R = n, m = n, s = 2, t = 0;
    while (m != 1) {
        if (t == 0) {
            R = L + s * ((R - L) / s);
        } else {
            L = R - s * ((R - L) / s);
        }
        m = (m + 1) / 2, s *= 2, t ^= 1;
    }
    cout << L;
}
