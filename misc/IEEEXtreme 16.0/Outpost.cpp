/**
 *    author:  MaGnsi0
 *    created: 22.10.2022 15:38:50
**/
#include <bits/stdc++.h>

using namespace std;

#define all(x) x.begin(), x.end()

template <typename T>
struct segment_tree {
    int N;
    T E;
    vector<T> S;
    function<T(T, T)> F;
    segment_tree(int n, T e, function<T(T, T)> f) : N(n), E(e), S(2 * n, e), F(f) {}
    void update(int j, T x) {
        for (S[j += N] = x; j /= 2;) {
            S[j] = F(S[2 * j], S[2 * j + 1]);
        }
    }
    T query(int L, int R) {
        T l = E, r = E;
        for (L += N, R += N; L < R; L /= 2, R /= 2) {
            if (L % 2) {
                l = F(l, S[L++]);
            }
            if (R % 2) {
                r = F(S[--R], r);
            }
        }
        return F(l, r);
    }
};

void solve30(int n, int m, int t) {
    const int OO = 1e9 + 5;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    segment_tree<int> b(n, 0, [](int x, int y) { return max(x, y); });
    segment_tree<int> c(n, OO, [](int x, int y) { return min(x, y); });
    for (int i = 0; i < n; ++i) {
        b.update(i, a[i]);
        c.update(i, a[i]);
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int l = 0, r = i;
        int low, high, lowm, highm;
        low = high = lowm = highm = i;
        while (l <= r) {
            int m = (l + r) / 2;
            if (b.query(m, i + 1) == a[i]) {
                low = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        l = i, r = n - 1; 
        while (l <= r) {
            int m = (l + r) / 2;
            if (b.query(i, m + 1) == a[i]) {
                high = m;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        l = low, r = i;
        while (l <= r) {
            int m = (l + r) / 2;
            if (a[i] - c.query(m, i + 1) <= t) {
                lowm = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        l = i, r = high;
        while (l <= r) {
            int m = (l + r) / 2;
            if (a[i] - c.query(i, m + 1) <= t) {
                highm = m;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        ans = max(ans, highm - lowm + 1);
    }
    cout << ans << "\n";
}

struct node{
        int mn, mx;
};

void solve(int n, int m, int t){
    const int N = 50100;
    vector<int> lg(N);
    vector<vector<vector<node>>> table(20, vector<vector<node>>(11, vector<node>(5001)));
    vector<vector<vector<node>>> x(10, vector<vector<node>>(10, vector<node>(5000)));
    vector<vector<int>> a(10, vector<int>(5000));
    function<node(node, node)> merge =  [&](node a, node b){
        node res;
        res.mn = min(a.mn, b.mn);
        res.mx = max(a.mx, b.mx);
        return res;
    };
    auto query = [&](int row, int l, int r){
            int len = r - l + 1;
            int k = lg[len];
            node ans= merge(table[k][row][l], table[k][row][r - (1 << k) + 1]);
            return ans;
    };
    for(int i = 2; i < N; i++)
            lg[i] = lg[i / 2] + 1;
        map<int,vector<int>> mp[n];
        for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                        cin>>a[i][j];
                        mp[i][a[i][j]].push_back(j);
                        table[0][i][j]= {a[i][j], a[i][j]};
                }
                for(int k = 1; k <= lg[m]; k++){
                        for(int j = 0; j + (1 << k) - 1 < m; j++){
                                table[k][i][j]= merge(table[k - 1][i][j],
                                                      table[k-1][i][j + (1 << (k-1))]);
                        }
                }
        }
        for(int j= 0; j < m; j++){
                for(int i1= 0; i1 < n; i1++){
                        node cur= {INT_MAX,INT_MIN};
                        for(int i2= i1; i2 < n; i2++){
                                cur= merge(cur, {a[i2][j], a[i2][j]});
                                x[i1][i2][j]= cur;
                        }
                }
        }
        int ans= 0;
        for(int r1= 0; r1 < n; r1++){
                for(int r2= r1; r2 < n; r2++){
                        for(int j1= 0; j1 < m; j1++){
                                int pos= -1, L= j1, R= m - 1;
                                int MAX= 0;
                                while(L <= R){
                                        int md= (L + R) / 2;
                                        node cur= {INT_MAX, INT_MIN};
                                        for(int row= r1; row <= r2; row++)
                                                cur= merge(cur, query(row, j1, md));
                                        cout.flush();
                                        if(cur.mx - cur.mn <= t){
                                                L= md + 1, MAX= cur.mx, pos= md;
                                        }
                                        else R= md - 1;
                                }
                                
                                if(pos == -1) continue;

                                int q = max({query(r1, j1, pos).mx, query(r2, j1, pos).mx,
                                             x[r1][r2][j1].mx, x[r1][r2][pos].mx});
        
                                if(q == MAX){
                                        ans= max(ans, (r2 - r1 + 1) * (pos - j1 + 1));
                                }else
                                {
                                        int j2= j1;
                                        for(int i = r1; i <= r2; i++){
                                                if(mp[i][MAX].size()){
                                                        int idx= lower_bound(all(mp[i][MAX]), pos) - mp[i][MAX].begin();
                                                        --idx;
                                                        
                                                        if(idx >= 0) j2= max(j2, mp[i][MAX][idx]);
                                                }
                                        }
                                        ans= max(ans, (r2 - r1 + 1) * (j2 - j1 + 1));
                                }
                        }
                }
        }
        
        cout<<ans<<"\n";
        return;
        for(int j1= 0; j1 < m; j1++){
                int L= j1, R= m - 1, pos= -1;
                while(L <= R){
                        int j2= (L + R) / 2;
                        
                }
//                for(int j2= j1; j2 < m; j2++){
//                        for(int r1= 0; r1 < n; r1++){
//                                node cur= {INT_MAX,INT_MIN};
//                                for(int r2= r1; r2 < n; r2++){
//                                        cur= merge(cur, query(r2, j1, j2));
//
//                                        if(cur.mx - cur.mn <= t){
//                                                int q = max({query(r1, j1, j2).mx, query(r2, j1, j2).mx,
//                                                             x[r1][r2][j1].mx, x[r1][r2][j2].mx});
//
//                                                if(q == cur.mx){
//                                                        ans= max(ans, (r2 - r1 + 1) * (j2 - j1 + 1));
//                                                }
//                                        }
//                                }
//                        }
//                }
        }
        cout<<ans<<"\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, t;
    cin >> n >> m >> t;
    if (n == 1) {
        swap(n, m);
    }
    if (m == 1) {
        solve30(n, m, t);
    } else {
        solve(n, m, t);
    }
}
