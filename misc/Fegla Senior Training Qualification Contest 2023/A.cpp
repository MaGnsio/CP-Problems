/**
 *    author:  MaGnsi0
 *    created: 26.02.2023 15:24:31
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
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int sum = 0;
        for (int j = i; j < n; ++j) {
            if ((sum | a[j]) == (sum + a[j])) {
                sum += a[j];
                ans++;
            } else {
                break;
            }
        }
    }
    cout << ans;
}
