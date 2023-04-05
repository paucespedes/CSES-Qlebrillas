#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n{0}, m{0};
ll sol{0};

int main()
{
    cin >> n >> m;

    vector<vector<bool>> map;
    vector<vector<bool>> vis;

    for (int i = 0; i < n; i++)
    {
        vector<bool> v(m, false);
        vis.push_back(v);
        map.push_back(v);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char c;
            cin >> c;
            if (c == '.')
                map[i][j] = true;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!map[i][j])
                continue;
            if (vis[i][j])
                continue;

            // Increment rooms
            sol++;

            // Process adjacents
            queue<pair<int, int>> q;
            q.push({i, j});

            while (!q.empty())
            {
                pair<int, int> s = q.front();
                q.pop();
                int ix = s.first, jx = s.second;

                if (((ix + 1) < n) && map[ix + 1][jx] && !vis[ix + 1][jx])
                {
                    q.push({ix + 1, jx});
                    vis[ix + 1][jx] = true;
                }

                if (((ix - 1) > -1) && map[ix - 1][jx] && !vis[ix - 1][jx])
                {
                    q.push({ix - 1, jx});
                    vis[ix - 1][jx] = true;
                }

                if (((jx - 1) > -1) && map[ix][jx - 1] && !vis[ix][jx - 1])
                {
                    q.push({ix, jx - 1});
                    vis[ix][jx - 1] = true;
                }

                if (((jx + 1) < m) && map[ix][jx + 1] && !vis[ix][jx + 1])
                {
                    q.push({ix, jx + 1});
                    vis[ix][jx + 1] = true;
                }
            }

        }
    }

    cout << sol << endl;

    return 0;
}