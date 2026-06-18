/**
 *    author:  MaGnsi0
 *    created: 18.06.2026 00:16:22
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int A, B, X; cin >> A >> B >> X;
        function<int(int, int)> F = [&](int a, int b) {
            if (a == b) { return 0; }
            if (a > b) { swap(a, b); }
            int ans = b - a;
            ans = min(ans, F(a, b / X) + 1);
            return ans;
        };
        cout << F(A, B) << "\n";
    }
}
