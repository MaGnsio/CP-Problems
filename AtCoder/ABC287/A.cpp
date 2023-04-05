/**
 *    author:  MaGnsi0
 *    created: 01.02.2023 21:37:42
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int x = count(a.begin(), a.end(), "For");
    cout << (x > n - x ? "Yes" : "No");
}
