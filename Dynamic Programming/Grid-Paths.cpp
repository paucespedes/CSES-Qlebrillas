#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef vector<int> vi;

ll tt, tt2, n, g, sol;
char x;

const ll M = 1000000007;

int main()
{
    cin >> n;

    ll tab[n][n];
    
    memset(tab, 0, sizeof(tab));

    for (tt = n; tt--;)
    {
        for (tt2 = n; tt2--;)
        {
            cin >> x;
            if (x == '*') tab[tt][tt2] = -1;
        }
    }

    if (!tab[0][0]) tab[0][0] = 1;

    for (tt = 0; tt < n; tt++)
    {
        for (tt2 = 0; tt2 < n; tt2++)
        {
            if (tab[tt][tt2] == -1) continue;

            if ((tt + 1 < n) && (tab[tt + 1][tt2] != -1))
                tab[tt + 1][tt2] = (tab[tt + 1][tt2] + tab[tt][tt2]) % M;

            if ((tt2 + 1 < n) && (tab[tt][tt2 + 1] != -1))
                tab[tt][tt2 + 1] = (tab[tt][tt2 + 1] + tab[tt][tt2]) % M;
        }
    }

    sol = tab[n - 1][n - 1] == -1 ? 0 : tab[n - 1][n - 1];

    cout << sol << "\n";

    return 0;
}