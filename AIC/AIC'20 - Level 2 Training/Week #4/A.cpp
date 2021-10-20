//https://vjudge.net/contest/433102#problem/A
#include <bits/stdc++.h>
using namespace std;

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    vector<int> v(4);
    for (auto& x : v) {
        cin >> x;
    }
    int k = v[0] + v[1] + v[2] + v[3];
    for (int mask = 0; mask < (1 << 4); ++mask) {
        int temp = k;
        for (int j = 0; j < 4; ++j) {
            if ((1 << j) & mask) {
                temp -= v[j];
            }
        }
        if (temp + temp == k) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
}

