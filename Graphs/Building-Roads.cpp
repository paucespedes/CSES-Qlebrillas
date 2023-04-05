#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n{0}, m{0};

vector<vector<int>> adj;
vector<bool> vis;

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++) adj.push_back({});

    for (int i = 0; i < n; i++) vis.push_back(false);
    
    for (int i = 0; i < m; i++)
    {
        ll a, b;
        cin >> a >> b;

        adj[a - 1].push_back(b - 1);
        adj[b - 1].push_back(a - 1);
    }
    
    vector<int> secs;

    for (int i = 0; i < n; i++)
    {
        if (vis[i]) continue;

        secs.push_back(i);

        queue<ll> q;
        q.push(i);
        while (!q.empty()) 
        {
            int s = q.front(); q.pop();

            for (auto u : adj[s]) 
            {
                if (vis[u]) continue;
                vis[u] = true;
                q.push(u);
            }
        }
    }

    cout << secs.size() - 1 << endl;

    for (int i = 0; i < secs.size() - 1; i++)
        cout << secs[i] + 1 << ' ' << secs[i + 1] + 1 << endl;

    return 0;
}