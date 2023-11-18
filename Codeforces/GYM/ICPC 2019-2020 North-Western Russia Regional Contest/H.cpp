/**
 *    author:  MaGnsi0
 *    created: 04.10.2023 21:50:50
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i < n; ++i) {
        a[i] += a[i - 1];
    }
    int Q; cin >> Q;
    vector<int> ans(N, -2);
    while (Q--) {
        int x; cin >> x;
        if (ans[x] != -2) {
            if (ans[x] == -1) {
                cout << "Impossible\n";
            } else {
                cout << ans[x] << "\n";
            }
            continue;
        }
        int j = 0, cnt = 0;
        while (j < n) {
            int low = j, high = n - 1, k = -1;
            while (low <= high) {
                int mid = (low + high) / 2;
                if (a[mid] - (j ? a[j - 1] : 0) <= x) {
                    k = mid;
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
            if (k == -1) { break; }
            j = k + 1;
            cnt++;
        }
        ans[x] = (j < n ? -1 : cnt);
        if (ans[x] == -1) {
            cout << "Impossible\n";
        } else {
            cout << ans[x] << "\n";
        }
    }
}
