#include <bits/stdc++.h>
using namespace std;

int maxN = 1e5 + 5, maxM = maxN * (maxN - 1); //those constraints are hypothetical and may not apply on the real algorithm
int cycle_begin = -1, cycle_end = -1;

vector<vector<int>> adj(maxN), adjT(maxN);
vector<vector<int>> adjm(maxN, vector<int>(maxN, 0));
vector<vector<pair<int, int>>> adj1(maxN);
vector<bool> visited(maxN, false), visited_edges(maxM, false), in_stack(maxN, 0);
vector<int> in(maxN, 0), out(maxN, 0), low(maxN, 0);
vector<int> parent(maxN, -1), color(maxN, 0);
vector<int> topological_order, in_deg(maxN, 0), out_deg(maxN, 0);
vector<int> eulerian_path;
vector<int> vertex_cover;
vector<pair<int, int>> E(maxM);

stack<int> st;

//normal dfs
//go as far as possible then back track
void dfs1(int v) {
    visited[v] = true;
    for (auto& u : adj[v]) {
        if (!visited[u]) {
            dfs1(u);
        }
    }
}

//dfs with timestamps
void dfs2(int v) {
    static int time = 0;
    visited[v] = true;
    in[v] = time++;
    for (auto& u : adj[v]) {
        if (!visited[u]) {
            dfs2(u);
        }
    }
    out[v] = time++;
}


//connected components
//run a series of dfs on each unvisited node (number of dfs runs == number of connected components)
int findCC() {
    int CC = 0;
    for (int i = 0; i < maxN; ++i) {
        if (!visited[i]) {
            dfs1(i);
            CC++;
        }
    }
    return CC;
}

//finding cycles in the graph (check if the graph is acyclic)
//undirected graph
bool dfs3(int v, int par = -1) {
    visited[v] = true;
    parent[v] = par;
    for (auto& u : adj[v]) {
        if (u == par) {
            continue;
        }
        if (visited[u]) {
            cycle_begin = u;
            cycle_end = v;
            return true;
        }
        if (dfs3(u, v)) {
            return true;
        }
    }
    return false;
}
//directed graph
bool dfs4(int v) {
    color[v] = 1;
    for (auto& u : adj[v]) {
        if (color[u] == 1) {
            cycle_begin = u;
            cycle_end = v;
            return true;
        } else if (color[u] == 0) {
            parent[u] = v;
            if (dfs4(u)) {
                return true;
            }
        }
    }
    color[v] = 2;
    return false;
}
//print cycle
void print_cycle() {
    if (cycle_begin == -1) {
        puts("NO CYCLE DETECTED");
        return;
    }
    vector<int> cycle;
    cycle.push_back(cycle_begin);
    for (int node = cycle_end; node != cycle_begin; node = parent[node]) {
        cycle.push_back(node);
    }
    cycle.push_back(cycle_begin);
    reverse(cycle.begin(), cycle.end());
    for (auto& node : cycle) {
        cout << node << " ";
    }
}

//topological sort using dfs
//topological sort == ordering nodes by their exit time (decreasing order)
//implementation assuming that the graph has no cycles
void dfs5(int v) {
    visited[v] = true;
    for (auto& u : adj[v]) {
        if (!visited[u]) {
            dfs5(u);
        }
    }
    topological_order.push_back(v);
}
//topological sort for all the graph components
void topological_sort() {
    for (int i = 0; i < maxN; ++i) {
        if (!visited[i]) {
            dfs5(i);
        }
    }
    reverse(topological_order.begin(), topological_order.end());
}
//topological sort using kahn's algorithm
void topological_sort_kahn() {
    queue<int> q; //we can use priority queue/set to get the lexicographically smallest(or largest) topological sort
    for (int i = 0; i < maxN; ++i) {
        if (!in_deg[i]) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        topological_order.push_back(v);
        for (auto& u : adj[v]) {
            in_deg[u]--;
            if (!in_deg[u]) {
                q.push(u);
            }
        }
    }
    if (topological_order.size() != maxN) {
        //graph has cycle -> no top-sort
        return;
    }
}
//all possible topological sort for graph (sorted)
void all_possible_top_sort() {
    for (int v = 0; v < maxN; ++v) {
        if (!in_deg[v]) {
            visited[v] = true;
            topological_order.push_back(v);
            for (auto& u : adj[v]) {
                in_deg[u]--;
            }
            all_possible_top_sort();
            visited[v] = false;
            topological_order.pop_back();
            for (auto& u : adj[v]) {
                in_deg[u]++;
            }
        }
    }
    if (topological_order.size() == maxN) {
        //we got one of possible orders
    }
}

//euler path: path that passes all edges exactly once.
//euler cycle: eulerian path that is a cycle (start node == end node).
/*
 *  euler path exists if:
 *      - undirected graph: start and end nodes have odd degress and all other nodes have even degrees.
 *      - directed graph: start node have one extra out_degree, end node have one extra in_degree, and all other nodes have in_degree = out_degree.
 *  euler cycle exists if:
 *      - undirected graph: all nodes have even degrees.
 *      - directed graph: in_degree = out_degree for every node.
 *  we can't make a graph that have odd number of nodes that have odd degree.
 */
//easy implementation to find eulerian cycle.
void find_euler_cycle(int v) {
    for (int u = 0; u < maxN; ++u) {
        if (adjm[v][u]) {
            adjm[v][u]--;
            adjm[u][v]--; //if the graph is undirected
            find_euler_cycle(u);
        }
    }
    eulerian_path.push_back(v);
}
//eulerian path/cycle algorithm (hierholzer's algorithm).
bool has_eulerian_path() { //checking if the graph have eulerian path/cycle or not.
    int start_nodes = 0, end_nodes = 0;
    for (int i = 0; i < maxN; ++i) {
        if (abs(in_deg[i] - out_deg[i]) > 1) {
            return false;
        }
        if (out_deg[i] - in_deg[i] == 1) {
            start_nodes++;
        } else if (in_deg[i] - out_deg[i] == 1) {
            end_nodes++;
        }
    }
    if ((start_nodes == 0 && end_nodes == 0) || (start_nodes == 1 && end_nodes == 1)) { //if eulerian cycle or eulerian path
        return true;
    } else {
        return false;
    }
}
void dfs6(int v) {
    while (out_deg[v]) {
        int u = adj[v][--out_deg[v]];
        //for undirected graph we have we have to skip node u -> v we some technique.
        dfs6(u);
    }
    eulerian_path.push_back(v);
}
void find_euler_path() {
    //count_in_out_deg
    for (int i = 0; i < maxN; ++i) {
        for (int j = 0; j < adj[i].size(); ++j) {
            out_deg[i]++;
            in_deg[j]++;
        }
    }
    //check if the graph have an eulerian path or not.
    if (!has_eulerian_path()) {
        //no eulrian path
        return;
    }
    //find start node.
    int start_node = -1;
    for (int i = 0; i < maxN; ++i) {
        if (out_deg[i] - in_deg[i] == 1) { //eulerian path
            start_node = i;
            break;
        }
        if (out_deg[i] > 0) { //eulerian cycle
            start_node = i;
        }
    }
    if (start_node == -1) { // graph consisting of maxN forests (ie. no edges)
        //no eulrian path
        return;
    }
    //build the path.
    dfs6(start_node);
    //check if the graph is disconnected.
    if (eulerian_path.size() != maxM + 1) {
        //graph is disconnected -> no eulerian path
        return;
    }
    reverse(eulerian_path.begin(), eulerian_path.end());
}

//finding bridges (cut edges) for undirected graph using dfs.
void dfs7(int v, int par = -1) {
    static int time = 0;
    visited[v] = true;
    in[v] = low[v] = time++;
    for (auto& u : adj[v]) {
        if (u == par) {
            continue;
        }
        if (visited[u]) { //back edge
            low[v] = min(low[v], in[u]);
        } else { //tree edge
            dfs7(u, v);
            low[v] = min(low[v], low[u]);
            if (in[v] < low[u]) { //no back edge from v or its ancestors to u or its descendants
                //cut edge
                //do something
            }
        }
    }
}

//finding articulation points (cut vertices) for undirected graph using dfs.
void dfs8(int v, int par = -1) {
    static int time = 0;
    visited[v] = true;
    in[v] = low[v] = time++;
    int childs = 0;
    for (auto& u : adj[v]) {
        if (u == par) {
            continue;
        }
        if (visited[u]) { //back edge
            low[v] = min(low[v], in[u]);
        } else { //tree edge
            dfs8(u, v);
            low[v] = min(low[v], low[u]);
            if (in[v] <= low[u] && par != -1) { //no back edge from v ancestors to u or its descendants (notice if the back edge connects v itself, it doesn't matter
                //cut vertex 
                //do something
            }
            childs++;
        }
    }
    if (par == -1 && childs > 1) {
        //root is cut vertex as well.
        //do something
    }
}

//finding strongly connected components (scc) in directed graph
/*
 *  scc is a maximal subset of vertices C such that any two vertices of this subset are reachable from each other.
 *  condensation graph is a graph containing every strongly connected component as one vertex.
 */
//kosaraju's algorithm.
/* 
 *  using dfs (building condensation graph)
 *  condensation graph is acyclic
 *  C1->C2 ---> out[C1] > out[C2] ---> we could reach C2 from C1 but not the opposite
 *  ---> so we run dfs on every vertex in the transposed graph after sorting them increasingly by their out time (topological sort).
 */
void dfs9(int v) {
    visited[v] = true;
    for (auto& u : adjT[v]) {
        if (!visited[u]) {
            dfs9(u);
        }
    }
}
void find_scc() {
    topological_sort();
    fill(visited.begin(), visited.end(), false);
    for (auto& v : topological_order) {
        if (!visited[v]) {
            dfs9(v);
            //component
        }
    }
}
//tarjan's algorithm.
void dfs10(int v, int& time) {
    in[v] = low[v] = time++;
    st.push(v);
    in_stack[v] = true;
    for (auto& u : adj[v]) {
        if (!in[u]) {
            dfs10(u, time);
        }
        if (in_stack[u]) {
            low[v] = min(low[u], low[v]);
        }
    }
    if (in[v] == low[v]) {
        while (st.top() != v) {
            int u = st.top();
            st.pop();
            in_stack[u] = false;
            low[u] = in[v];
        }
        st.pop();
        in_stack[v] = true;
    }
}
void scc_tarjan() {
    int time = 1;
    for (int i = 0; i < maxN; ++i) {
        if (!in[i]) {
            dfs10(i, time);
        }
    }
}

//strong orientation(turn connected undirected graph to strong connected directed graph)
void orient(int v) {
    static int time = 0;
    low[v] = in[v] = time++;
    for (auto& [u, i] : adj1[v]) {
        if (visited_edges[i]) {
            continue;
        }
        visited_edges[i] = true;
        if (v == E[i].second) {
            //v --> u
            swap(E[i].first, E[i].second);
        }
        if (in[u] == -1) { // if u is not visited yet
            orient(u);
            low[v] = min(low[v], low[u]);
            if (in[v] < low[u]) {
                //cut edge
                //do something
            }
        } else {
            low[v] = min(low[v], in[u]);
        }
    }
}

//vertex cover of a tree
bool dfs11(int v, int par = -1) {
    bool is_cover = false;
    for (auto& u : adj[v]) {
        if (u != par) {
            is_cover |= dfs11(u, v);
        }
    }
    if (is_cover) {
        vertex_cover.push_back(v);
    }
    return !is_cover;
}

//bipartite graph (all cycle have even number of nodes) (color every direct connect nodes with two different colors).
bool dfs12(int v, int c = 0) {
    visited[v] = true;
    color[v] = c;
    for (auto& u : adj[v]) {
        if (visited[u] && color[u] == color[v]) {
            return false;
        }
        if (!visited[u] && !dfs12(u, c ^ 1)) {
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
}
