//https://atcoder.jp/contests/abc199/tasks/abc199_a
#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int A, B, C;
    cin >> A >> B >> C;
    cout << ((A * A) + (B * B) < (C * C) ? "Yes" : "No");
}
