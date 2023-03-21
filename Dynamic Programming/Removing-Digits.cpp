#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef vector<int> vi;

ll tt, n, g, sol;
ll x;

int main()
{
    cin >> g;

    ll tab[g + 1];
    
    memset(tab, 0, sizeof(tab));    
    
    for (ll nn = g; nn > 0; nn--)
    {
        if (!tab[nn] && nn != g) continue;

        x = nn;

        while (x)
        {
            if (!(x % 10))
            {
                x /= 10;
                continue;
            }

            ll mm = nn - (x % 10);

            if (mm >= 0)
            {
                if (!tab[mm]) tab[mm] = tab[nn] + 1;
                else tab[mm] = min(tab[mm], tab[nn] + 1);
            }

            x /= 10;
        }
    }
    
    sol = tab[0];

    cout << sol << "\n";

    return 0;
}