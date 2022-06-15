/**
 *    author:  MaGnsi0
 *    created: 12.03.2022 19:09:59
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("disagreements.in", "r", stdin);
    set<long long> s;
    for (int i = 0; i < 3; ++i) {
        long long x;
        cin >> x;
        s.insert(x);
    }
    cout << ((int)s.size() < 3 ? "YES" : "NO");
}
