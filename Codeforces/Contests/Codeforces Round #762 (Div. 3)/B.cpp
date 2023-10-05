/**
 *    author:  MaGnsi0
 *    created: 05.01.2022 21:24:42
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    set<long long> s;
    for (long long i = 1; i * i <= 1e9; ++i) {
        s.insert(i * i);
    }
    for (long long i = 1; i * i * i <= 1e9; ++i) {
        s.insert(i * i * i);
    }
    vector<long long> a(s.begin(), s.end());
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        cout << upper_bound(a.begin(), a.end(), n) - a.begin() << "\n";
    }
}
