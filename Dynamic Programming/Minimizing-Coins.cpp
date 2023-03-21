#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef vector<int> vi;

ll tt, n, g, sol;
ll x;

int main()
{
    cin >> n >> g;

    vi c;

    ll tab[g + 1];
    
    memset(tab, 0, sizeof(tab));

    for (tt = n; tt--;)
    {
        cin >> x;
        if (x > g) continue;
        
        c.push_back(x);
        tab[x] = 1;
    }

    sort(c.begin(), c.end());

    for (ll nn = 1; nn < g + 1; nn++)
    {
        if (!tab[nn]) continue;

        for (ll mm = 0; mm < n; mm++)
        {
            if ((nn + c[mm]) > g) break;

            if (!tab[nn + c[mm]]) tab[nn + c[mm]] = tab[nn] + 1;
            else tab[nn + c[mm]] = min(tab[nn + c[mm]], tab[nn] + 1);
        }
   
    }
    
    sol = !tab[g] ? -1 : tab[g];

    cout << sol << "\n";

    return 0;
}