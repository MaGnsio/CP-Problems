/**
 *    author:  MaGnsi0
 *    created: 04.02.2023 09:01:08
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int m;
    cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    sort(b.begin(), b.end());
    for (int i = 0; i < n; ++i) {
        int l = 0, r = m - 1, ans1 = -1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (b[mid] >= a[i]) {
                ans1 = b[mid];
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        int ans2 = -1;
        l = 0, r = m - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (b[mid] <= a[i]) {
                ans2 = b[mid];
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        if (ans1 == -1) {
            cout << ans2 << "\n";
        } else if (ans2 == -1) {
            cout << ans1 << "\n";
        } else {
            if (ans1 - a[i] <= a[i] - ans2) {
                cout << ans1 << "\n";
            } else {
                cout << ans2 << "\n";
            }
        }
    }
}
