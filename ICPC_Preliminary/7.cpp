#include <bits/stdc++.h>
using namespace std;

static const int dx[4] = {-1, 0, 1, 0};
static const int dy[4] = {0, 1, 0, -1};

int N, M;
vector<string> grid;

struct Mirror {
    int x, y;
    char type;
};
vector<Mirror> mirrors;

int sx, sy, tx, ty;
vector<pair<int,int>> lasers;

bool in(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < M;
}

int reflectDir(int dir, char mirror) {
    if (mirror == '/') {
        if (dir == 0) return 1;
        if (dir == 1) return 0;
        if (dir == 2) return 3;
        return 2;
    } else { // '\'
        if (dir == 0) return 3;
        if (dir == 3) return 0;
        if (dir == 2) return 1;
        return 2;
    }
}

void simulateLasers(vector<vector<int>> &unsafe, vector<string> &g) {
    for (auto &p : lasers) {
        int x = p.first, y = p.second;
        for (int d = 0; d < 4; d++) {
            int cx = x, cy = y, dir = d;
            while (1) {
                cx += dx[dir];
                cy += dy[dir];
                if (!in(cx, cy)) break;
                if (g[cx][cy] == '#') break;
                unsafe[cx][cy] = 1;
                if (g[cx][cy] == '/' || g[cx][cy] == '\\') {
                    dir = reflectDir(dir, g[cx][cy]);
                }
            }
        }
    }
}

bool bfs(vector<vector<int>> &unsafe, vector<string> &g) {
    if (unsafe[sx][sy]) return false;
    queue<pair<int,int>> q;
    vector<vector<int>> vis(N, vector<int>(M, 0));
    q.push({sx, sy});
    vis[sx][sy] = 1;

    while (!q.empty()) {
        auto [x,y] = q.front(); q.pop();
        if (x == tx && y == ty) return true;

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (!in(nx, ny)) continue;
            if (vis[nx][ny]) continue;
            if (g[nx][ny] == '#') continue;
            if (unsafe[nx][ny]) continue;
            vis[nx][ny] = 1;
            q.push({nx, ny});
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    grid.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> grid[i];
        for (int j = 0; j < M; j++) {
            char c = grid[i][j];
            if (c == 'S') sx = i, sy = j;
            if (c == 'T') tx = i, ty = j;
            if (c == 'L') lasers.push_back({i, j});
            if (c == '/' || c == '\\')
                mirrors.push_back({i, j, c});
        }
    }

    int K = mirrors.size();
    int total = 1 << K;

    long long valid = 0;
    long long bestCost = LLONG_MAX;

    for (int mask = 0; mask < total; mask++) {
        vector<string> g = grid;

        int cost = 0;
        for (int i = 0; i < K; i++) {
            int x = mirrors[i].x;
            int y = mirrors[i].y;
            char orig = mirrors[i].type;
            char now = ((mask >> i) & 1) ? (orig == '/' ? '\\' : '/') : orig;
            if (now != orig) cost++;
            g[x][y] = now;
        }

        vector<vector<int>> unsafe(N, vector<int>(M, 0));
        simulateLasers(unsafe, g);

        if (bfs(unsafe, g)) {
            valid++;
            bestCost = min(bestCost, (long long)cost);
        }
    }

    if (valid == 0) {
        cout << 0 << " " << -1 << "\n";
    } else {
        cout << valid << " " << bestCost << "\n";
    }

    return 0;
}
