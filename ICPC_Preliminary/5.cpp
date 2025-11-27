#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, t;
};

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, delta;
    if (!(cin >> n >> m >> delta)) return 0;

    vector<Edge> all_edges(m);
    vector<pair<int, int>> adj[5005];     
    vector<pair<int, int>> rev_adj[5005]; 

    for (int i = 0; i < m; i++) 
    {
        cin >> all_edges[i].u >> all_edges[i].v >> all_edges[i].t;

        adj[all_edges[i].u].push_back({all_edges[i].v, all_edges[i].t});
        rev_adj[all_edges[i].v].push_back({all_edges[i].u, all_edges[i].t});

    }

    for (int i = 0; i <= n; i++) 
    {
        sort(adj[i].begin(), adj[i].end());
        sort(rev_adj[i].begin(), rev_adj[i].end());
    }

    vector<int> uniq_out[5005], uniq_in[5005];
    for (int i = 0; i <= n; i++) 
    {
        for (auto p : adj[i]) {
            if (uniq_out[i].empty() || uniq_out[i].back() != p.first) {
                uniq_out[i].push_back(p.first);
            }
        }
        for (auto p : rev_adj[i]) 
        {
            if (uniq_in[i].empty() || uniq_in[i].back() != p.first) {
                uniq_in[i].push_back(p.first);
            }
        }
    }

    long long cnt1 = 0, cnt2 = 0, cnt3 = 0;

    for (int i = 0; i < m; i++) 
    
    {
        int u = all_edges[i].u;
        int v = all_edges[i].v;
        int t2 = all_edges[i].t;

        for (int A : uniq_in[u]) 
        {
            if (A == v) continue;
            
            vector<int> t1s, t3s;
            
            auto it1 = lower_bound(rev_adj[u].begin(), rev_adj[u].end(), make_pair(A, -1));
            while(it1 != rev_adj[u].end() && it1->first == A) 
            {
                if (it1->second < t2) t1s.push_back(it1->second);
                it1++;
            }
            if (t1s.empty()) continue;

            auto it3 = lower_bound(adj[v].begin(), adj[v].end(), make_pair(A, -1));
            while(it3 != adj[v].end() && it3->first == A) 
            {
                if (it3->second > t2) t3s.push_back(it3->second);
                it3++;
            }
            if (t3s.empty()) continue;

            for (int t1 : t1s) 
            {
                auto it = upper_bound(t3s.begin(), t3s.end(), t1 + delta);
                cnt1 += (it - t3s.begin());
            }
        }

        for (int B : uniq_out[u]) 
        {

            if (B == v) continue;

            vector<int> t1s, t3s;

            auto it1 = lower_bound(adj[u].begin(), adj[u].end(), make_pair(B, -1));

            while(it1 != adj[u].end() && it1->first == B) 
            {
                if (it1->second < t2) t1s.push_back(it1->second);
                it1++;
            }
            if (t1s.empty()) continue;

            auto it3 = lower_bound(adj[B].begin(), adj[B].end(), make_pair(v, -1));


            while(it3 != adj[B].end() && it3->first == v) 
            {
                if (it3->second > t2) t3s.push_back(it3->second);
                it3++;
            }
            if (t3s.empty()) continue;

            for (int t1 : t1s) 
            {
                auto it = upper_bound(t3s.begin(), t3s.end(), t1 + delta);
                cnt2 += (it - t3s.begin());
            }
        }

        for (int A : uniq_in[v]) 
        {
            if (A == u) continue;

            vector<int> t1s, t3s;

            auto it1 = lower_bound(rev_adj[v].begin(), rev_adj[v].end(), make_pair(A, -1));
            while(it1 != rev_adj[v].end() && it1->first == A) 
            {
                if (it1->second < t2) t1s.push_back(it1->second);
            it1++;
            }

            if (t1s.empty()) continue;

            auto it3 = lower_bound(adj[v].begin(), adj[v].end(), make_pair(A, -1));
            while(it3 != adj[v].end() && it3->first == A) 
            {


                if (it3->second > t2) t3s.push_back(it3->second);
            it3++;
            }
            if (t3s.empty()) continue;

            for (int t1 : t1s) {

                auto it = upper_bound(t3s.begin(), t3s.end(), t1 + delta);
                cnt3 += (it - t3s.begin());


            }
        }
    }

    cout << cnt1 << " " << cnt2 << " " << cnt3 << endl;



}

//