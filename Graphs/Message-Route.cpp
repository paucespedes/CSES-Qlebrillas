#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n{0}, m{0};

vector<vector<int>> adj;
vector<bool> vis;

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        adj.push_back({});

    for (int i = 0; i < n; i++)
        vis.push_back(false);

    for (int i = 0; i < m; i++)
    {
        ll a, b;
        cin >> a >> b;

        adj[a - 1].push_back(b - 1);
        adj[b - 1].push_back(a - 1);
    }

    ll prev[n]; 
    for (int i = 0; i < n; i++) prev[i] = -1;

    queue<ll> q;
    q.push(0);
    vis[0] = true;

    while (!q.empty())
    {
        int s = q.front();
        q.pop();

        for (auto u : adj[s])
        {
            if (vis[u]) continue;
            prev[u] = s;
            vis[u] = true;
            q.push(u);
        }
    }

    if (vis[n - 1])
    {
        /* Calculate path */
        vector<int> path;
        ll cur = n - 1;
        while (cur != 0)
        {
            path.push_back(cur);
            cur = prev[cur];
        }

        path.push_back(0);

        cout << path.size() << endl;
        for (int i = path.size() - 1; i > -1; i--) cout << path[i] + 1 << " ";
        cout << endl;


    } else cout << "IMPOSSIBLE" << endl;

    return 0;
}