//https://codeforces.com/contest/1480/problem/B
#include <bits/stdc++.h>
using namespace std;

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    long long t;
    cin >> t;
    while (t--) {
        long long A, B, N;
        cin >> A >> B >> N;
        vector<long long> a(N), b(N);
        for (auto& x : a)
            cin >> x;
        for (auto& x : b)
            cin >> x;
        long long dmg = 0, chk = 0;
        for (long long i = 0; i < N; ++i)
            dmg += ((b[i] + A - 1) / A) * a[i];
        for (long long i = 0; i < N; ++i) {
            if (B - dmg + a[i] > 0) {
                chk = 1;
                break;
            }
        }
        cout << (chk ? "YES\n" : "NO\n");
    }
}

