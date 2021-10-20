//https://vjudge.net/contest/417537#problem/B
#include <bits/stdc++.h>
using namespace std;

vector<int> g(32, 0), f(32, 0);

bool is_beautiful () {
    for (int bit = 0; bit < 32; ++bit) {
        if (g[bit] != 0 && f[bit] == 0) {
            return false;
        }
    }
    return true;
}

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int> (32));
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        bitset<32> b(x);
        for (int bit = 0; bit < 32; ++bit)
        {
            v[i][bit] = b[bit];
            g[bit] += b[bit];
        }
    }
    int i = 0, j = 0, ans = n;
    while (i <= j && i < n) {
        while (j < n && !is_beautiful ()) {
            for (int bit = 0; bit < 32; ++bit) {
                f[bit] += v[j][bit];
            }
            j++;
        }
        if (is_beautiful ()) {
            ans = min (ans, j - i);
        }
        for (int bit = 0; bit < 32; ++bit) {
            f[bit] -= v[i][bit];
        }
        i++;
    }
    cout << max (ans, 1);
}
