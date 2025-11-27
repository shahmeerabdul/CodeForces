#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<pair<ll,ll>> outEdges[5005];
vector<pair<ll,ll>> inEdges[5005];

struct LogEntry {
    ll fr, t, time;
};

vector<LogEntry> logs;
vector<ll> bufferList[5005];
vector<ll> tempList;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m, D;
    if (!(cin >> n >> m >> D)) return 0;

    for (ll i = 0; i < m; i++) {
        ll u, v, t;
        cin >> u >> v >> t;
        logs.push_back({u, v, t});
        outEdges[u].push_back({t, v});
        inEdges[v].push_back({t, u});
    }

    for (int i = 0; i <= n; i++) {
        sort(outEdges[i].begin(), outEdges[i].end());
        sort(inEdges[i].begin(), inEdges[i].end());
    }

    sort(logs.begin(), logs.end(), [&](const LogEntry &a, const LogEntry &b){
        return a.time < b.time;
    });

    ll cnt1 = 0, cnt2 = 0, cnt3 = 0;

    for (auto &log : logs) {
        ll u = log.fr;
        ll v = log.t;
        ll t = log.time;

        auto L1 = lower_bound(inEdges[u].begin(), inEdges[u].end(), make_pair(t - D, -1LL));
        for (auto it = L1; it != inEdges[u].end(); it++) {
            if (it->first >= t) break;
            ll x = it->second;
            if (x == v) continue;
            if (bufferList[x].empty()) tempList.push_back(x);
            bufferList[x].push_back(it->first);
        }

        auto R1 = upper_bound(outEdges[v].begin(), outEdges[v].end(), make_pair(t, (ll)1e18));
        for (auto it = R1; it != outEdges[v].end(); it++) {
            ll t3 = it->first;
            if (t3 > t + D) break;
            ll x = it->second;
            if (x == u) continue;
            for (ll t1 : bufferList[x]) {
                if (t3 - t1 <= D) cnt1++;
            }
        }

        for (ll x : tempList) bufferList[x].clear();
        tempList.clear();

        auto L2 = lower_bound(outEdges[u].begin(), outEdges[u].end(), make_pair(t - D, -1LL));
        for (auto it = L2; it != outEdges[u].end(); it++) {
            if (it->first >= t) break;
            ll x = it->second;
            if (x == v) continue;
            if (bufferList[x].empty()) tempList.push_back(x);
            bufferList[x].push_back(it->first);
        }

        auto R2 = upper_bound(inEdges[v].begin(), inEdges[v].end(), make_pair(t, (ll)1e18));
        for (auto it = R2; it != inEdges[v].end(); it++) {
            ll t3 = it->first;
            if (t3 > t + D) break;
            ll x = it->second;
            if (x == u) continue;
            for (ll t1 : bufferList[x]) {
                if (t3 - t1 <= D) cnt2++;
            }
        }

        for (ll x : tempList) bufferList[x].clear();
        tempList.clear();

        auto L3 = lower_bound(inEdges[v].begin(), inEdges[v].end(), make_pair(t - D, -1LL));
        for (auto it = L3; it != inEdges[v].end(); it++) {
            if (it->first >= t) break;
            ll x = it->second;
            if (x == u) continue;
            if (bufferList[x].empty()) tempList.push_back(x);
            bufferList[x].push_back(it->first);
        }

        auto R3 = upper_bound(outEdges[v].begin(), outEdges[v].end(), make_pair(t, (ll)1e18));
        for (auto it = R3; it != outEdges[v].end(); it++) {
            ll t3 = it->first;
            if (t3 > t + D) break;
            ll x = it->second;
            if (x == u) continue;
            for (ll t1 : bufferList[x]) {
                if (t3 - t1 <= D) cnt3++;
            }
        }

        for (ll x : tempList) bufferList[x].clear();
        tempList.clear();
    }

    cout << cnt1 << " " << cnt2 << " " << cnt3 << "\n";
    return 0;
}
