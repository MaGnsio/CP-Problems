/**
 *    author:  MaGnsi0
 *    created: 07.10.2023 21:11:08
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("B1.in", "r", stdin);
    freopen("B1.out", "w", stdout);
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int n; cin >> n;
        int sum = 0;
        vector<int> ans;
        for (int i = 2; i * i <= n; ++i) {
            while (n % i == 0) {
                ans.push_back(i);
                sum += i;
                n /= i;
            }
        }
        if (n > 1) {
            ans.push_back(n);
            sum += n;
        }
        cout << "Case #" << t << ": ";
        if (sum > 41) {
            cout << "-1\n";
            continue;
        }
        while (sum++ < 41) { ans.push_back(1); }
        sort(ans.begin(), ans.end());
        cout << (int)ans.size();
        for (int x : ans) {
            cout << " " << x;
        }
        cout << "\n";
    }
}
