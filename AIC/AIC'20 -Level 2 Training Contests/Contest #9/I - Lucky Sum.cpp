//https://vjudge.net/contest/435043#problem/I
#include <bits/stdc++.h>
using namespace std;

vector<long long> lucky;

void init (string s = "0") {
    if (stoll(s)) {
        lucky.push_back(stoll(s));
    }
    if (stoll(s) > 1000000000) {
        return;
    }
    init(s + "4");
    init(s + "7");
}

int main () {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    long long l, r, ans = 0;
    cin >> l >> r;
    init();
    sort(lucky.begin (), lucky.end ());
    long long last = l;
    for (long long i = 0; i < lucky.size (); ++i) {
        if (lucky[i] < l) {
            continue;
        }
        ans += (min (lucky[i], r) - last + 1) * lucky[i];
        last = lucky[i] + 1;
        if (lucky[i] >= r) {
            break;
        }
    }
    cout << ans;
}

