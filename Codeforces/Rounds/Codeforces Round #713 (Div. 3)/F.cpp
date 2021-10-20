//https://codeforces.com/contest/1512/problem/F
#include <bits/stdc++.h>
using namespace std;

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int t;
    cin >> t;
    while (t--) {
        long long n, c;
        cin >> n >> c;
        vector<long long> a(n), b(n - 1);
        for (auto& x : a)
            cin >> x;
        for (auto& x : b)
            cin >> x;
        long long curc = 0, curd = 0;
        vector<long long> ans;
        for (long long i = 0; i < n; ++i) {
            ans.push_back (curd + (c - curc + a[i] - 1) / a[i]);
            if (i < n - 1) {
                long long p = (max (b[i] - curc, 0LL) + a[i] - 1) / a[i];
                curc = curc + p * a[i] - b[i];
                curd += (p + 1);
            }
        }
        cout << *min_element (ans.begin (), ans.end ()) << "\n";
    }
}

