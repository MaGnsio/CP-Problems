//https://codeforces.com/gym/102680/problem/E
#include <bits/stdc++.h>
using namespace std;

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int t;
    cin >> t;
    while (t--) {
        long long q, n;
        cin >> q >> n;
        long long cnt = 0, m = 1, k = n;
        while (q) {
            long long mini = min (q, k);
            cnt += (mini * m);
            q -= mini;
            k *= n;
            m++;
        }
        cout << cnt << "\n";
    }
}

