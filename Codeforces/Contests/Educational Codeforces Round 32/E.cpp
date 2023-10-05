/**
 *    author:  MaGnsi0
 *    created: 08/08/2021 20:25:23
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n, m, res = 0;
    cin >> n >> m;
    vector<int> a(n), v;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i] %= m;
    }
    for (int mask = 0; mask < (1 << (n / 2)); ++mask) {
        int sum = 0;
        for (int i = 0; i < n / 2; ++i) {
            if ((1 << i) & mask) {
                sum += a[i];
                sum %= m;
            }
        }
        v.push_back(sum);
    }
    sort(v.begin(), v.end());
    for (int mask = 0; mask < (1 << (n - n / 2)); ++mask) {
        int sum = 0;
        for (int i = n / 2; i < n; ++i) {
            if ((1 << (i - n / 2)) & mask) {
                sum += a[i];
                sum %= m;
            }
        }
        int l = 0, r = v.size() - 1, k = sum;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (v[mid] + sum < m) {
                k = v[mid] + sum;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        k = max(k, v[v.size() - 1]);
        res = max(res, k);
    }
    cout << res;
}
