/**
 *    author:  MaGnsi0
 *    created: 31.10.2022 19:24:44
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
        a++, b++;
        int64_t A = a - 1, B = b - 1, X = -1, Y = -1;
        for (int64_t i = 1; i * i <= A * B; ++i) {
            if ((A * B) % i) {
                continue;
            }
            int64_t x = i * ((a + i - 1) / i);
            int64_t y = ((A * B) / i) * ((b + ((A * B) / i) - 1) / ((A * B) / i));
            if (x <= c && y <= d) {
                X = x, Y = y;
                break;
            }
            x = ((A * B) / i) * ((a + ((A * B) / i) - 1) / ((A * B) / i));
            y = i * ((b + i - 1) / i);
            if (x <= c && y <= d) {
                X = x, Y = y;
                break;
            }
        }
        cout << X << " " << Y << "\n";
    }
}
