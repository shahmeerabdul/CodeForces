#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005; // Standard limit for N
const int LOG = 20;      // Sufficient for N <= 10^6 (2^20 > 10^6)

vector<int> adj[MAXN];
int up[MAXN][LOG];       // up[u][i] stores the 2^i-th ancestor of u
int depth[MAXN];
int n, q, r;

// DFS to setup depths and direct parents (2^0-th ancestor)
void dfs(int u, int p, int d) {
    depth[u] = d;
    up[u][0] = p; // Direct parent
    
    // Fill binary lifting table for node u
    for (int i = 1; i < LOG; i++) {
        if (up[u][i-1] != 0) {
            up[u][i] = up[up[u][i-1]][i-1];
        } else {
            up[u][i] = 0; // No ancestor at this level
        }
    }

    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u, d + 1);
        }
    }
}

// Function to find the k-th ancestor
int get_kth_ancestor(int node, int k) {
    // Optimization: If k is larger than the depth, ancestor doesn't exist
    if (k > depth[node]) return -1; 

    for (int i = 0; i < LOG; i++) {
        // If the i-th bit of k is set ((k >> i) & 1)
        if ((k >> i) & 1) {
            node = up[node][i];
            if (node == 0) return -1; // Should be covered by depth check, but safety
        }
    }
    return node;
}

void solve() {
    if (!(cin >> n >> q >> r)) return;

    // Clear adjacency list and table for each test case
    for (int i = 0; i <= n; i++) {
        adj[i].clear();
        for (int j = 0; j < LOG; j++) {
            up[i][j] = 0;
        }
    }

    // Reading edges
    // Note: Problem gives "parent-child" lines but sample input logic implies
    // we should treat them as undirected and root the tree at 'r'.
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Preprocessing from the root 'r'
    // Parent of root is 0 (sentinel)
    dfs(r, 0, 0);

    // Processing Queries
    while (q--) {
        int u, k;
        cin >> u >> k;
        cout << get_kth_ancestor(u, k) << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}