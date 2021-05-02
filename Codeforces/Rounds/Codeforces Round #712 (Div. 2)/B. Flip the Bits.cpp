//https://codeforces.com/contest/1504/problem/B
#include <bits/stdc++.h>
using namespace std;

void solve () {
    int n, pre = 0;
    string a, b;
    cin >> n >> a >> b;
    a.push_back ('0');
    b.push_back ('0');
    for (int i = 0; i < n; ++i) {
        pre += (a[i] == '1') - (a[i] == '0');
        if ((a[i] == b[i]) != (a[i + 1] == b[i + 1]) && pre != 0) {
                cout << "NO\n";
                return;
        }
    }
    cout << "YES\n";
}

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int t;
    cin >> t;
    while (t--)
        solve ();
}

