/**
 *    author:  MaGnsi0
 *    created: 02.06.2022 16:18:35
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    int Mahmoud = 0, Bashar = 0;
    map<int, int> c, d;
    for (int i = 0; i < n; ++i) {
        Mahmoud += c[k - a[i]];
        Bashar += d[k - b[i]];
        c[a[i]]++, d[b[i]]++;
    }
    cout << (Mahmoud == Bashar ? "Draw" : (Mahmoud > Bashar ? "Mahmoud" : "Bashar"));
}
