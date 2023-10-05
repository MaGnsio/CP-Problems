/**
 *    author:  MaGnsi0
 *    created: 21.09.2023 11:39:04
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, t;
    cin >> n >> t;
    int s1 = 0, s2 = 0;
    for (int i = 0; i < n; ++i) {
        char p; cin >> p;
        int s; cin >> s;
        if (p == 'P') {
            s1 += s;
        } else {
            s2 += s;
        }
    }
    cout << fixed << setprecision(6);
    if (4 * s1 * t == 12 * s2 * t) {
        double ans = 4.0 * s2 / t;
        cout << ans;
    } else if (4 * s1 * t < 12 * s2 * t) {
        double t1 = (4.0 * s1) / (3.0 * t);
        double t2 = 1.0 * (s2 - (t1 * t / 4.0)) / t;
        double ans = t1 + t2;
        cout << ans;
    } else {
        double t1 = (4.0 * s2) / t;
        double t2 = 1.0 * (s1 - (3.0 * t1 * t / 4.0)) / t;
        double ans = t1 + t2;
        cout << ans;
    }
}
