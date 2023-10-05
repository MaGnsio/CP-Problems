/**
 *    author:  MaGnsi0
 *    created: 04.09.2022 15:40:56
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int64_t n, d;
    cin >> n >> d;
    vector<int64_t> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int64_t ans = 0, l = 0;
    for (int i = n - 1; i >= 0; --i) {
        int number_of_members = (d + a[i]) / a[i];
        if (i - l + 1 < number_of_members) {
            break;
        }
        l += number_of_members - 1;
        ans++;
    }
    cout << ans;
}
