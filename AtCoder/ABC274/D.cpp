/**
 *    author:  MaGnsi0
 *    created: 25.10.2022 08:04:39
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    set<int> dpx;
    dpx.insert(a[0]);
    for (int i = 2; i < n; i += 2) {
        set<int> ndpx;
        for (auto& x : dpx) {
            ndpx.insert(x + a[i]);
            ndpx.insert(x - a[i]);
        }
        dpx = ndpx;
    }
    set<int> dpy;
    dpy.insert(a[1]);
    dpy.insert(-a[1]);
    for (int i = 3; i < n; i += 2) {
        set<int> ndpy;
        for (auto& y : dpy) {
            ndpy.insert(y + a[i]);
            ndpy.insert(y - a[i]);
        }
        dpy = ndpy;
    }
    cout << (dpx.count(x) && dpy.count(y) ? "Yes" : "No");
}
