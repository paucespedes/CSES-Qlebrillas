#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll M = 1000000007;

int a, b;

int main()
{
    cin >> a >> b;
    if (a > b) swap(a, b);

    int tab[a][b];

    for (int i = 0; i < a; i++)
        for (int j = 0; j < b; j++)
            tab[i][j] = i == j ? 0 : INT16_MAX;

    for (int i = 0; i < a; i++)
    {
        for (int j = i; j < b; j++)
        {
            for(int k = 1; k <= (i + 1)/2; k++)
                tab[i][j] = min(tab[i][j], tab[i - k][j] + tab[k - 1][j] + 1);

            for (int k = 1; k <= (j + 1)/2; k++)
                tab[i][j] = min(tab[i][j], tab[i][j - k] + tab[i][k - 1] + 1);

            if (i < b && j < a) tab[j][i] = tab[i][j];
        }
    }

    cout << tab[a - 1][b - 1] << "\n";

    return 0;
}