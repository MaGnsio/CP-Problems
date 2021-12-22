/**
 *    author:  MaGnsi0
 *    created: 20.11.2021 14:10:08
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        int a1, a2, a3;
        cin >> a1 >> a2 >> a3;
        a[i] = a1 + a2 + a3;
    }
    vector<int> b = a;
    sort(b.begin(), b.end(), greater<int>());
    int x = b[k - 1];
    for (int i = 0; i < n; ++i) {
        cout << (a[i] + 300 >= x ? "Yes" : "No") << "\n";
    }
}
