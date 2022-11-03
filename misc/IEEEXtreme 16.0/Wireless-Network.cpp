/**
 *    author:  MaGnsi0
 *    created: 22.10.2022 18:11:44
**/
#include <bits/stdc++.h>

using namespace std;

struct UnionFind{
        vector<int> sz, parent;
        int forests;
        
        UnionFind(int n){
                sz = vector<int> (n);
                parent = vector<int> (n);
                forests = n;
                
                for(int i = 0; i < n; i++){
                        sz[i] = 1, parent[i] = i;
                }
        }
        int find_set(int x){
                if(x == parent[x]) return x;
                return parent[x] = find_set(parent[x]);
        }
        void link(int x, int y){
                if(sz[x] > sz[y]) swap(x, y);
                
                parent[x] = y;
                sz[y] += sz[x];
        }
        bool union_sets(int x, int y){
                x = find_set(x);
                y = find_set(y);
                
                if(x != y){
                        link(x, y);
                        forests--;
                }
                return x != y;
        }
};
struct edge{
        int from, to, w;
        edge(int from, int to, int w):from(from), to(to), w(w){}
        
        bool operator < (const edge & e) const {
                return w > e.w;
        }
};

int kruskal(vector<edge> edgeList, int n){
        UnionFind uf(n);
        vector<edge> edges;
        int mstCost = 0;
        priority_queue<edge> pq;
        for(int i = 0; i < edgeList.size(); i++)
                pq.push(edgeList[i]);
        while(!pq.empty()){
                edge e = pq.top();
                pq.pop();
                if(uf.union_sets(e.from, e.to)){
                        mstCost += e.w;
                        edges.push_back(e);
                }
        }
        return mstCost;
}

int solve(set<int> upgraded_towers, vector<vector<int>> edges, int n){
        int res= 0;
        vector<edge> edgeList;
        for(auto e : edges){
                if(e[3]){
                        if(upgraded_towers.find(e[0]) != upgraded_towers.end()
                        || upgraded_towers.find(e[1]) != upgraded_towers.end()){
                                edgeList.push_back(edge(e[0], e[1], e[2]));
                        }
                }else{
                    return INT_MAX;
                        edgeList.push_back(edge(e[0], e[1], e[2]));
                }
        }
        return kruskal(edgeList, n);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    map<string, int> mp;
    vector<vector<int>> a(n, vector<int>(4));
    vector<int> b;
    for (int i = 0, j = 0; i < n; ++i) {
        int c, h;
        string u, v;
        cin >> u >> v >> c >> h;
        if (!mp.count(u)) {
            mp[u] = j++;
        }
        if (!mp.count(v)) {
            mp[v] = j++;
        }
        a[i][0] = mp[u], a[i][1] = mp[v];
        a[i][2] = c, a[i][3] = h;
        if (h == 1) {
            b.push_back(mp[u]);
            b.push_back(mp[v]);
        }
    }
    sort(b.begin(), b.end());
    b.resize(unique(b.begin(), b.end()) - b.begin());
    int m = (int)b.size();
    assert(m <= 12);
    int ans = INT_MAX;
    for (int i = 0; i < (1 << m); ++i) {
        set<int> s;
        for (int j = 0; j < m; ++j) {
            if ((i >> j) & 1) {
                s.insert(b[j]);
            }
        }
        ans = min(ans, solve(s, a, (int)mp.size()) + (int)s.size() * 10000);
    }
    cout << ans;
}
