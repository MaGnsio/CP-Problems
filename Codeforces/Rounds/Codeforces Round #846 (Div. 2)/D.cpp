/**
 *    author:  MaGnsi0
 *    created: 25.01.2023 17:18:16
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    function<int(int)> subtract = [&](int x) {
        cout << "- " << x << endl;
        int pop_count;
        cin >> pop_count;
        return pop_count;
    };
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int ans = 0, cur_n = n;
        for (int i = 0; i < 30; ++i) {
            if (__builtin_popcount(ans) == n) {
                break;
            }
            int new_n = subtract(1 << i);
            if (new_n == cur_n - 1) {
                ans |= (1 << i);
            } else {
                ans |= (1 << (i + new_n - cur_n + 1));
                i += new_n - cur_n + 1;
            }
            cur_n = new_n;
        }
        cout << "! " << ans << endl;
    }
}
