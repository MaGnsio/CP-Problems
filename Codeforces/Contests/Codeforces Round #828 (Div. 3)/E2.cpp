/**
 *    author:  MaGnsi0
 *    created: 31.10.2022 21:41:18
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int64_t a, b, c, d;
        cin >> a >> b >> c >> d;
        vector<int64_t> A, B;
        for (int64_t i = 1; i * i <= a; ++i) {
            if (a % i == 0) {
                A.push_back(i);
                if (a != i * i) {
                    A.push_back(a / i);
                }
            }
        }
        for (int64_t i = 1; i * i <= b; ++i) {
            if (b % i == 0) {
                B.push_back(i);
                if (b != i * i) {
                    B.push_back(b / i);
                }
            }
        }
        int X = -1, Y = -1;
        for (int i = 0; i < (int)A.size(); ++i) {
            for (int j = 0; j < (int)B.size(); ++j) {
                int64_t x = A[i] * B[j];
                int64_t y = a * b / gcd(x, a * b);
                x = x * (c / x);
                y = y * (d / y);
                if (a < x && b < y) {
                    X = x, Y = y;
                }
            }
        }
        cout << X << " " << Y << "\n";
    }
}
