#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

ll mod = 1e9 + 7;
const int N = 3e5 + 10;
ll factorial[N];

ll power(ll a, ll b){
    if(b < 0) return 1;
    ll res = 1;
    while(b){
        if(b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

ll mod_inv(ll n){
    return power(n, mod - 2);
}

ll nck(ll n, ll a){
    if(n < a) return 0;
    ll top = factorial[n];
    ll bot = mod_inv(factorial[a]) * mod_inv(factorial[n - a]); bot %= mod;
    ll res = top * bot % mod;
    return res;
}

void init(){
    factorial[0] = 1;
    for(int i = 1; i < N; i++){
        factorial[i] = factorial[i - 1] * i;
        factorial[i] %= mod;
    }
}

int n, m, k, l;
vector<int> nodes, edges;
vector<vector<int>> adj;

int timer;
vector<int> tin, tout;
vector<vector<int>> up;

void dfs(int v, int p)
{
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];

    for (int u : adj[v]) {
        if (u != p)
            dfs(u, v);
    }

    tout[v] = ++timer;
}

bool is_ancestor(int u, int v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v)
{
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

void preprocess(int root) {
    tin.resize(n);
    tout.resize(n);
    timer = 0;
    l = ceil(log2(n));
    up.assign(n, vector<int>(l + 1));
    dfs(root, root);
}

ll ans= 0;
void dfs2(int node, int p= 0){
    for(int ch : adj[node])
    {
        if(ch != p)
        {
            dfs2(ch, node);
            nodes[node] += nodes[ch];
            edges[node] += edges[ch];
        }
    }
    ans += nck(nodes[node], k);
    ans %= mod;
    ans -= nck(edges[node], k);
    ans %= mod;
    if(ans < 0) ans += mod;
}
void solve()
{
    cin>>n>>m>>k;
    adj= vector<vector<int>> (n);
    nodes= vector<int> (n);
    edges= vector<int> (n);

    for(int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin>>u>>v;
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }
    preprocess(0);
    while(m--)
    {
        int ui, vi;
        cin>>ui>>vi; --ui, --vi;
        if(ui == vi)
        {
            nodes[ui]++;
            if(ui) nodes[up[ui][0]]--;
            continue;
        }
        if(is_ancestor(ui, vi))
        {
            edges[vi]++;
            edges[ui]--;
            nodes[vi]++;
            if(ui != 0) nodes[up[ui][0]]--;
        }else if(is_ancestor(vi, ui)){
            swap(ui, vi);
            edges[vi]++;
            edges[ui]--;
            nodes[vi]++;
            if(ui != 0) nodes[up[ui][0]]--;
        }else
        {
            int r= lca(ui, vi);
            edges[ui]++;
            edges[vi]++;
            edges[r] -= 2;
            nodes[ui]++;
            nodes[vi]++;
            nodes[r]--;
            if(r) nodes[up[r][0]]--;
        }
    }
    ans= 0;
    dfs2(0);
    cout<<ans<<"\n";
}
int32_t  main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    init();

    int T; cin>>T;
    while(T--) solve();
}
