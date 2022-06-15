/**
 *    author:  MaGnsi0
 *    created: 20.03.2022 06:09:53
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        string n;
        cin >> n;
        int sum = 0;
        for (int i = 0; i < (int)n.size(); ++i) {
            sum += (n[i] - '0');
        }
        sum %= 9;
        cout << "Case #" << t << ": ";
        sum = 9 - sum;
        string ans = "";
        bool choosen = false;
        if (sum == 9) {
            ans += n[0];
            sum = 0;
        }
        for (int i = (sum ? 0 : 1); i < (int)n.size(); ++i) {
            if (choosen) {
                ans += n[i];
            } else {
                if ((n[i] - '0') > sum) {
                    ans += to_string(sum);
                    ans += n[i];
                    choosen = true;
                } else {
                    ans += n[i];
                }
            }
        }
        if (ans == n) {
            ans += to_string(sum);
        }
        cout << ans << "\n";
    }
}
