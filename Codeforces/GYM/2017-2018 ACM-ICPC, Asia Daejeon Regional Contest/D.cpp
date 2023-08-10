#include <bits/stdc++.h>

using namespace std;

int64_t F(int64_t x) {
    int64_t ans = 0;
    while (x) {
        ans += (x % 10) * (x % 10);
        x /= 10;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int64_t n;
    cin >> n;
    set<int64_t> s;
    while (true) {
        if (s.count(n)) { break; }
        if (n == 1) {
            cout << "HAPPY";
            return 0;
        }
        s.insert(n);
        n = F(n);
    }
    cout << "UNHAPPY";
}
