/**
 *    author:  MaGnsi0
 *    created: 22.02.2025 14:01:26
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end(), [](string s, string t) {
        return (int)s.size() < (int)t.size();
    });
    for (int i = 0; i < n; ++i) {
        cout << a[i];
    }
}
