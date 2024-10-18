/**
 *    author:  MaGnsi0
 *    created: 18.10.2024 20:17:03
**/
#include <bits/stdc++.h>

using namespace std;

bool ask(int64_t h) {
    cout << h << endl;
    string s; cin >> s;
    if (s == "fail") { exit(0); }
    return s == "wet" ? false : true;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int64_t limit = 1;
    while (true) {
        if (ask(limit)) { break; }
        limit *= 2;
    }
    int64_t low = 1, high = limit, ans = limit;
    while (low <= high) {
        int64_t mid = low + (high - low) / 2;
        if (ask(mid)) {
            ans = mid; high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    cout << "! " << ans << endl;
}
