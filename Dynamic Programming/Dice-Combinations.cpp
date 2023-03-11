#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll tt;

unordered_map<int, int> memo;

ll M = 1000000007;

int f(int n)
{
    if (memo.find(n) != memo.end()) return memo[n];
    if (n == 0) return 1;

    int sol = 0;

    for (int i = 1; i <= 6; i++)
    {
        if ((n - i) >= 0) sol = (sol + f(n - i)) % M;
    }

    memo[n] = sol % M;
    return memo[n];
}


int main()
{
    cin >> tt;

    cout << f(tt) << "\n";

    return 0;
}