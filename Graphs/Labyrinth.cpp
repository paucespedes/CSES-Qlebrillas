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
    vector<vector<char>> mov;

    vector<char> path;

    pair<int, int> a;
    pair<int, int> b;

    for (int i = 0; i < n; i++)
    {
        vector<bool> v(m, false);
        vector<char> c(m, 'N');
        vis.push_back(v);
        map.push_back(v);
        mov.push_back(c);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char c;
            cin >> c;
            if (c != '#') map[i][j] = true;
            if (c == 'A') a = {i, j};
            if (c == 'B') b = {i, j};
        }
    }

    queue<pair<int, int>> q;
    q.push(a);
    vis[a.first][a.second] = true;

    while (!q.empty())
    {
        pair<int, int> x = q.front();
        if (x == b) break;

        q.pop();

        int i = x.first, j = x.second;

        if (((i - 1) > -1) && map[i - 1][j] && !vis[i - 1][j])
        {
            vis[i - 1][j] = true;
            
            mov[i - 1][j] = 'U';
            
            q.push({i - 1, j});
        }

        if (((i + 1) < n) && map[i + 1][j] && !vis[i + 1][j])
        {
            vis[i + 1][j] = true;
            mov[i + 1][j] = 'D';
            q.push({i + 1, j});
        }

        if (((j - 1) > -1) && map[i][j - 1] && !vis[i][j - 1])
        {
            vis[i][j - 1] = true;
            mov[i][j - 1] = 'L';
            q.push({i, j - 1});
        }

        if (((j + 1) < m) && map[i][j + 1] && !vis[i][j + 1])
        {
            vis[i][j + 1] = true;
            mov[i][j + 1] = 'R';
            q.push({i, j + 1});
        }
    }

    if (vis[b.first][b.second])
    {
        cout << "YES" << endl;

        pair<int, int> cur = b;
        while (cur != a)
        {
            path.push_back(mov[cur.first][cur.second]);

            switch (mov[cur.first][cur.second])
            {
            case 'U': cur = {cur.first + 1, cur.second}; break;
            case 'D': cur = {cur.first - 1, cur.second}; break;
            case 'R': cur = {cur.first, cur.second - 1}; break;
            case 'L': cur = {cur.first, cur.second + 1}; break;
            default: break;
            }
        }

        cout << path.size() << endl;

        for (int i = path.size() - 1; i > -1; i--) cout << path[i];
        cout << endl;
    }
    else cout << "NO" << endl;
    
    return 0;
}