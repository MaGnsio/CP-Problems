/**
 *    author:  MaGnsi0
 *    created: 12.03.2022 20:15:27
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("circles.in", "r", stdin);
    int T;
    cin >> T;
    while (T--) {
        vector<long long> x(3), y(3);
        for (int i = 0; i < 3; ++i) {
            cin >> x[i] >> y[i];
        }
        set<pair<int, int>> s;
        for (int i = 0; i < 3; ++i) {
            s.insert({x[i], y[i]});
        }
        if (s.size() < 3) {
            cout << "Possible\n";
            continue;
        }
        long long a = ((x[1] * y[2]) - (x[2] * y[1])) - ((x[0] * y[2]) - (x[2] * y[0])) + ((x[0] * y[1]) - (x[1] * y[0]));
        cout << (a == 0 ? "Impossible" : "Possible") << "\n";
    }
}
