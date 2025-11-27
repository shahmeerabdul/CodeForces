#include <bits/stdc++.h>
using namespace std;

const int INF = 2147483647;

vector<int> sievePrimes(int n) {
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i)
                isPrime[j] = false;
        }
    }
    vector<int> primes;
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) primes.push_back(i);
    }
    return primes;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string line;
    while (getline(cin, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        int N, R, E, T;
        ss >> N >> R >> E >> T;

        vector<vector<pair<int, int>>> g(N + 1);
        for (int i = 0; i < R; i++) {
            getline(cin, line);
            stringstream edge(line);
            int u, v, d;
            edge >> u >> v >> d;
            if (u <= N && v <= N) {
                g[u].push_back({v, d});
            }
        }

        vector<int> dist(N + 1, INF);
        dist[1] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, 1});

        while (!pq.empty()) {
            auto [du, u] = pq.top(); pq.pop();
            if (du != dist[u]) continue;
            for (auto [v, w] : g[u]) {
                if (dist[v] > du + w) {
                    dist[v] = du + w;
                    pq.push({dist[v], v});
                }
            }
        }

        int ansDist = dist[E];
        vector<int> primes = sievePrimes(T - 1);
        int sum = 0;
        for (int i = primes.size() - 1, cnt = 0; i >= 0 && cnt < 3; i--, cnt++) {
            sum += primes[i];
        }

        cout << ansDist << " " << sum << "\n";
    }

    return 0;
}