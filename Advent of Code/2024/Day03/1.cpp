/**
 *    author:  MaGnsi0
 *    created: 03.12.2024 16:28:25
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    string in;
    int64_t ans = 0;
    function<pair<int, int>(int)> mul = [&](int j) {
        if (j + 3 >= n || in.substr(j, 4) != "mul(") {
            return make_pair(0, 0);
        }
        int d1 = 0;
        for (int i = j + 4; /*_*/; ++i) {
            if (i >= n || !isdigit(in[i])) { break; }
            d1++;
        }
        if (d1 < 1 || d1 > 3) {
            return make_pair(0, 0);
        }
        if (j + 3 + d1 + 1 >= n || in[j + 3 + d1 + 1] != ',') {
            return make_pair(0, 0);
        }
        int d2 = 0;
        for (int i = j + 3 + d1 + 2; /*_*/; ++i) {
            if (i >= n || !isdigit(in[i])) {
                break;
            }
            d2++;
        }
        if (d2 < 1 || d2 > 3) {
            return make_pair(0, 0);
        }
        if (j + 3 + d1 + 1 + d2 + 1 >= n || in[j + 3 + d1 + 1 + d2 + 1] != ')') {
            return make_pair(0, 0);
        }
        return make_pair(stoi(in.substr(j + 4, d1)) * stoi(in.substr(j + 3 + d1 + 2, d2)), d1 + d2 + 5);
    };
    while (cin >> in) {
        n = (int)in.size();
        for (int i = 0; i < n; /*_*/) {
            auto [x, k] = mul(i);
            i += k + 1; ans += x;
        }
    }
    cout << ans;
}
