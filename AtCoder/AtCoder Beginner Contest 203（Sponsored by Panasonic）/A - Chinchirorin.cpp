//https://atcoder.jp/contests/abc203/tasks/abc203_a
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int A, B, C;
    cin >> A >> B >> C;
    if (A == B) {
        cout << C;
    } else if (A == C) {
        cout << B;
    } else if (B == C) {
        cout << A;
    } else {
        cout << 0;
    }
}
