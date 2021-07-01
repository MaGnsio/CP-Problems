//https://atcoder.jp/contests/abc202/tasks/abc202_b
#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    string S;
    cin >> S;
    reverse(S.begin(), S.end());
    for (auto& c : S) {
        if (c == '0' || c == '1' || c == '8') {
            continue;
        }
        c = (c == '9' ? '6' : '9');
    }
    cout << S;
}
