/**
 *    author:  MaGnsi0
 *    created: 23.10.2023 03:04:10
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int64_t> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int low = 0, high = n - 1;
    int64_t larges = 0, smalls = 0;
    int64_t added = 0, removed = 0;
    for (int k = 2; k <= n; ++k) {
        if (k % 2 == 0) {
            smalls += a[low++];
            larges += a[high--];
            added += larges;
            removed += smalls;
        } else {
            added += larges;
            removed += smalls;
        }
        cout << added - removed << " ";
    }
}
