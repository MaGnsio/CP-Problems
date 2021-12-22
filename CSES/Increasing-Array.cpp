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
    long long res = 0;
    for (int i = 1; i < n; ++i) {
        res += max(1LL * (a[i - 1] - a[i]), 0LL);
        a[i] = max(a[i], a[i - 1]);
    }
    cout << res;
}
