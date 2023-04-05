#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n{0}, m{0};

vector<vector<int>> adj;
vector <int> team;

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++) adj.push_back({});

    for (int i = 0; i < n; i++) team.push_back(0);
    
    for (int i = 0; i < m; i++)
    {
        ll a, b;
        cin >> a >> b;

        adj[a - 1].push_back(b - 1);
        adj[b - 1].push_back(a - 1);
    }

    for (int i = 0; i < n; i++)
    {
        if (team[i]) continue;

        queue<ll> q;
        q.push(i);
        team[i] = 1;

        while (!q.empty()) 
        {
            int s = q.front(); q.pop();

            for (auto u : adj[s]) 
            {
                if (team[u] && team[u] == team[s])
                {
                    cout << "IMPOSSIBLE" << endl;
                    return 0;
                }

                if (!team[u])
                {
                    team[u] = team[s] == 1 ? 2 : 1;
                    q.push(u);
                }
            }
        }
    }

    for (int i = 0; i < team.size(); i++) cout << team[i] << ' ';

    cout << endl;

    return 0;
}