#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
vector<int> adj[MAXN];
int color[MAXN];
int dist[MAXN];
bool visited_comp[MAXN];
int N, W;

// Check if a component is Bipartite and collect its nodes
bool is_bipartite(int start, vector<int>& component) {
    queue<int> q;
    q.push(start);
    color[start] = 0;
    visited_comp[start] = true;
    component.push_back(start);

    bool possible = true;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            if (color[v] == -1) {
                color[v] = 1 - color[u];
                visited_comp[v] = true;
                component.push_back(v);
                q.push(v);
            } else if (color[v] == color[u]) {
                possible = false;
            }
        }
    }
    return possible;
}

// Run BFS to find the longest path starting from a specific node
int bfs_farthest(int start) {
    // Reset distance array for this BFS run
    for (int i = 1; i <= N; i++) dist[i] = -1;
    
    queue<int> q;
    q.push(start);
    dist[start] = 0;
    int max_d = 0;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        max_d = max(max_d, dist[u]);
        
        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return max_d;
}

void solve() {
    if (!(cin >> N)) return;
    cin >> W;

    // Reset data structures
    for (int i = 1; i <= N; i++) {
        adj[i].clear();
        color[i] = -1;
        visited_comp[i] = false;
    }

    for (int i = 0; i < W; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int total_districts = 0;

    // Process each connected component
    for (int i = 1; i <= N; i++) {
        if (!visited_comp[i]) {
            vector<int> component;
            // Step 1: Check Bipartite
            if (!is_bipartite(i, component)) {
                cout << -1 << endl;
                return;
            }
            
            // Step 2: Find Diameter of this component
            // Since N <= 1000, we can run BFS from every node in the component
            int max_dia = 0;
            for (int node : component) {
                max_dia = max(max_dia, bfs_farthest(node));
            }
            total_districts += (max_dia + 1);
        }
    }
    cout << total_districts << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t) {
        while (t--) solve();
    }
    return 0;
}