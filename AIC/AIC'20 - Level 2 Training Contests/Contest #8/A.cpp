//https://vjudge.net/contest/433801#problem/A
#include <bits/stdc++.h>
using namespace std;
const int sz = 1e6 + 1;

vector<int> cnt (sz, 1);

void init () {
    for (int i = 2; i < sz; ++i) {
        for (int j = i; j < sz; j += i) {
            cnt[j]++;
        }
    }
}

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    init ();
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        int k = gcd (a, b);
        cout << cnt[k] << "\n";
    }
}

