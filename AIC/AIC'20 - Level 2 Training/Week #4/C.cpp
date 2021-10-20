//https://vjudge.net/contest/433102#problem/C
#include <bits/stdc++.h>
using namespace std;

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto& x : v) {
        cin >> x;
    }
    for (int mask = 0; mask < (1 << n); ++mask) {
        int x = 0;
        for (int j = 0; j < n; ++j) {
            if ((1 << j) & mask) {
                x = (x + v[j] + 360) % 360;
            }
            else {
                x = (x - v[j] + 360) % 360;
            }
        }
        if (x == 0) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
}

