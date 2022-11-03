/**
 *    author:  MaGnsi0
 *    created: 29.08.2022 02:30:08
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 101;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int n, k;
        cin >> n >> k;
        vector<int> a(N);
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a[x]++;
        }
        int maxf = *max_element(a.begin(), a.end());
        cout << "Case #" << t << ": ";
        cout << (maxf <= 2 && 2 * k >= n ? "YES" : "NO") << "\n";
    }
}
