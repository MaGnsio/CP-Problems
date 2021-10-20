#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    while (T--) {
        int N = (1 << 18), n;
        cin >> n;
        vector<int> masks(N, 0);
        for (int i = 0; i < n; ++i) {
            int a;
            cin >> a;
            int flibed_a = (~a) & (N - 1);
            for (int submask = flibed_a; ; submask = (submask - 1) & flibed_a) {
                masks[submask | a] |= a;
                if (submask == 0) {
                    break;
                }
            }
        }
        int res = 0;
        for (int i = 0; i < N; ++i) {
            res += (masks[i] == i);
        }
        cout << res << "\n";
    }
}
