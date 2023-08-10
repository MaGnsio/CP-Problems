/**
 *    author:  MaGnsi0
 *    created: 25.06.2023 18:24:44
**/
#include <bits/stdc++.h>

using namespace std;

/**
 * Time: Approximately O(E^2)
 */

#include <bits/extc++.h>

const int64_t OO = INT64_MAX / 4;

struct MCMF {
    int N;
    vector<vector<int>> ed, red;
    vector<vector<int64_t>> cap, flow, cost;
    vector<int> seen;
    vector<int64_t> dist, pi;
    vector<pair<int, int>> par;
    MCMF(int N) :
        N(N), ed(N), red(N), cap(N, vector<int64_t>(N)), flow(cap),
        cost(cap), seen(N), dist(N), pi(N), par(N) {}
    void addEdge(int from, int to, int64_t cap, int64_t cost) {
        this -> cap[from][to] = cap;
        this -> cost[from][to] = cost;
        ed[from].push_back(to);
        red[to].push_back(from);
    }
    void path(int s) {
        fill(seen.begin(), seen.end(), 0);
        fill(dist.begin(), dist.end(), OO);
        int64_t di; dist[s] = 0;
        __gnu_pbds::priority_queue<pair<int64_t, int>> q;
        vector<decltype(q)::point_iterator> its(N);
        q.push({0, s});
        auto relax = [&](int i, int64_t cap, int64_t cost, int dir) {
            int64_t val = di - pi[i] + cost;
            if (cap && val < dist[i]) {
                dist[i] = val;
                par[i] = {s, dir};
                if (its[i] == q.end()) {
                    its[i] = q.push({-dist[i], i});
                } else {
                    q.modify(its[i], {-dist[i], i});
                }
            }
        };
        while (!q.empty()) {
            s = q.top().second; q.pop();
            seen[s] = 1; di = dist[s] + pi[s];
            for (int i : ed[s]) {
                if (!seen[i]) {
                    relax(i, cap[s][i] - flow[s][i], cost[s][i], 1);
                }
            }
            for (int i : red[s]) {
                if (!seen[i]) {
                    relax(i, flow[i][s], -cost[i][s], 0);
                }
            }
        }
        for (int i = 0; i < N; ++i) {
            pi[i] = min(pi[i] + dist[i], OO);
        }
    }
    pair<int64_t, int64_t> maxflow(int s, int t) {
        int64_t totflow = 0, totcost = 0;
        while (path(s), seen[t]) {
            int64_t fl = OO;
            for (int p, r, x = t; tie(p,r) = par[x], x != s; x = p) {
                fl = min(fl, r ? cap[p][x] - flow[p][x] : flow[x][p]);
            }
            totflow += fl;
            for (int p, r, x = t; tie(p,r) = par[x], x != s; x = p) {
                if (r) {
                    flow[p][x] += fl;
                } else {
                    flow[x][p] -= fl;
                }
            }
        }
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                totcost += cost[i][j] * flow[i][j];
            }
        }
        return {totflow, totcost};
    }
    // If some costs can be negative, call this before maxflow:
    void setpi(int s) { // (otherwise, leave this out)
        fill(pi.begin(), pi.end(), OO); pi[s] = 0;
        int it = N, ch = 1; int64_t v;
        while (ch-- && it--) {
            for (int i = 0; i < N; ++i) {
                if (pi[i] != OO) {
                    for (int to : ed[i]) {
                        if (cap[i][to]) {
                            if ((v = pi[i] + cost[i][to]) < pi[to]) {
                                pi[to] = v, ch = 1;
                            }
                        }
                    }
                }
            }
        }
        assert(it >= 0); // negative cost cycle
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int64_t> a(m), b(m), c(m), d(m);
    for (int i = 0; i < m; ++i) {
        cin >> a[i] >> b[i] >> c[i];
        a[i]--, b[i]--, d[i] = i;
    }
    sort(d.begin(), d.end(), [&](int64_t i, int64_t j) {
            return c[i] < c[j];
        });
    function<int64_t(int)> F = [&](int x) {
        MCMF flow(n);
        for (int i = 0; c[d[i]] < c[d[x]]; ++i) {
            flow.addEdge(a[d[i]], b[d[i]], 1, 1);
            flow.addEdge(b[d[i]], a[d[i]], 1, 1);
        }
        int64_t ans = flow.maxflow(a[d[x]], b[d[x]]).first;
        return ans;
    };
    int64_t ans = 0;
    for (int i = 0; i < m; ++i) {
        ans += F(i);
    }
    cout << ans;
}
