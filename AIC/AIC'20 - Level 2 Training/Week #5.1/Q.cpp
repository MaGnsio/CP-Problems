//https://vjudge.net/contest/434102#problem/Q
#include <bits/stdc++.h>
using namespace std;

void solve (int n, int m, int& cnt) {
    if (m % n != 0) {
        cnt = -1;
        return;
    }
    if (n == m) {
        return;
    }
    if ((m / n) % 3 == 0) {
        cnt++;
        solve (n * 3, m, cnt);
    } else if ((m / n) % 2 == 0) {
        cnt++;
        solve (n * 2, m, cnt);
    } else {
        cnt = -1;
        return;
    }
}

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n, m, cnt = 0;
    cin >> n >> m;
    solve (n, m, cnt);
    cout << cnt;
}

