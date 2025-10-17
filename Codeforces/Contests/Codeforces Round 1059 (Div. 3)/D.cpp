/**
 *    author:  MaGnsi0
 *    created: 17.10.2025 17:59:02
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    function<int(int, int, int)> ask = [&](int x, int l, int r) {
        cout << x << " " << l << " " << r << endl;
        int sum; cin >> sum; return sum;
    };
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int m = ask(2, 1, n) - (n * (n + 1) / 2);
        int low = 1, high = n, L = n - m + 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            int sum1 = ask(1, 1, mid);
            int sum2 = ask(2, 1, mid);
            if (sum1 != sum2) {
                high = mid - 1, L = mid;
            } else {
                low = mid + 1;
            }
        }
        cout << "! " << L << " " << L + m - 1 << endl;
    }
}
