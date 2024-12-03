/**
 *    author:  MaGnsi0
 *    created: 03.12.2024 16:49:06
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    string in;
    bool add = true;
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
    function<bool(int)> check_do = [&](int j) {
        return j + 3 < n && in.substr(j, 4) == "do()";
    };
    function<bool(int)> check_do_not = [&](int j) {
        return j + 6 < n && in.substr(j, 7) == "don't()";
    };
    while (cin >> in) {
        n = (int)in.size();
        for (int i = 0; i < n; /*_*/) {
            if (check_do(i)) {
                i += 4; add = true;
            } else if (check_do_not(i)) {
                i += 7; add = false;
            } else {
                auto [x, k] = mul(i);
                i += k + 1;
                if (add) { ans += x; }
            }
        }
    }
    cout << ans;
}
