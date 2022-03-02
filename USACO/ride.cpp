/*
ID: magnsi01
LANG: C++
TASK: ride
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("ride.in", "r", stdin);
    freopen("ride.out", "w", stdout);
    string s, t;
    cin >> s >> t;
    auto f = [](string s) {
        int x = 1;
        for (auto& c : s) {
            x *= (c - 'A' + 1);
            x %= 47;
        }
        return x;
    };
    cout << (f(s) == f(t) ? "GO" : "STAY") << "\n";
}
