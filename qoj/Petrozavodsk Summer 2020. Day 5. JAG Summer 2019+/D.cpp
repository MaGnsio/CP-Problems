/**
 *    author:  MaGnsi0
 *    created: 12.11.2023 10:44:12
**/
#include <bits/stdc++.h>

using namespace std;

struct union_find {
    vector<int> parent, length;
    union_find(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        length = vector<int>(n, 1);
    }
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    void unite(int x, int y) {
        int Px = find(x);
        int Py = find(y);
        if (Px == Py) {
            return;
        }
        if (length[Px] < length[Py]) {
            swap(Px, Py);
        }
        parent[Py] = Px;
        length[Px] += length[Py];
    }
};

__int128 power(__int128 a, __int128 b, __int128 modd){
    __int128 res = 1;
    while (b) {
        if (b & 1) { res = res * a % modd; }
        a = a * a % modd;
        b >>= 1;
    }
    return res;
}

__int128 gcd(__int128 a, __int128 b, __int128 &x, __int128 &y){
    if(b == 0){
        x = 1;
        y = 0;
        return  a;
    }
    __int128 x1, y1;
    __int128 d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

vector<pair<__int128, __int128>> vp[210];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i]; a[i]--;
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i]; b[i]--;
    }
    vector<int> time(n, -1);
    union_find dsu(n);
    for (int t = 0; t <= n + 1; ++t) {
        for (int i = 0; i < n; ++i) {
            if (a[i] == i && time[i] == -1) {
                time[i] = t;
            }
        }
        vector<int> new_a(n);
        for (int i = 0; i < n; ++i) {
            new_a[i] = b[a[i]];
            dsu.unite(b[a[i]], a[i]);
        }
        a = new_a;
    }
    if (count(time.begin(), time.end(), -1)) {
        cout << -1;
        return 0;
    }
    if (count(time.begin(), time.end(), 0) == n) {
        cout << 0;
        return 0;
    }
    set<int> ps;
    for (int i = 0; i < n; ++i) {
        ps.insert(dsu.find(i));
        if (time[i] != time[dsu.find(i)]) {
            cout << -1;
            return 0;
        }
    }
    vector<__int128> mods, rs, ignore;
    for (int p : ps) {
        int rem = time[p] % dsu.length[p];
        int mod = dsu.length[p];
        for (int i = 2; i <= mod; ++i) {
            if (mod % i == 0) {
                int pr = 1;
                while (mod % i == 0){
                    mod /= i;
                    pr *= i;
                }
                vp[i].emplace_back(pr, rem % pr);
            }
        }
    }
    for(int i = 2; i <= 200; i++){
        if(vp[i].size() == 0) continue;
        sort(vp[i].begin(), vp[i].end());
        vp[i].erase(unique(vp[i].begin(), vp[i].end()), vp[i].end());
        auto [pwr, rem] = vp[i].back();
        for(int j = 0; j + 1 < vp[i].size(); ++j){
            auto [curpwr, currem]= vp[i][j];
            if(rem % curpwr != currem){
                cout << -1;
                return 0;
            }
        }
        mods.push_back(pwr);
        rs.push_back(rem);
    }
    __int128 M = mods[0];
    __int128 R = rs[0];
    for(int i = 1; i < (int)rs.size(); ++i) {
        __int128 a = M, b = mods[i], c = rs[i] - R;
        __int128 q1, q2, d = gcd(a, b, q1, q2);
        assert(c % d == 0);
        q1 *= c / d;
        R += q1 * M;
        M  = (M / __gcd(M, mods[i])) * mods[i];
        R = (R % M + M) % M;
    }
    cout << int64_t(R);
}
