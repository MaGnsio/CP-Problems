/**
 *    author:  MaGnsi0
 *    created: 13.08.2022 15:57:27
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
        a[i]--;
    }
    vector<int> c(n);
    for (int i = 0; i < n; ++i) {
        c[i] = a[i] == i;
    }
    for (int i = 1; i < n; ++i) {
        c[i] += c[i - 1];
    }
    int64_t ans = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] == i) {
            ans += c[i] - 1;
        } else if (a[i] > i && a[a[i]] == i) {
            ans += a[a[i]] == i;
        }
    }
    cout << ans;
}
