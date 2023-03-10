#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<long> vl;
typedef vector<long long> vll;
 
ll n, m, x, y;
ll nn, mm;
ll sol = 0, c = 0;
 
vl a, b;
 
int main()
{
    cin >> n;
    nn = n;
 
    for (;nn--;)
    {
        cin >> x >> y;
        a.push_back(x);
        b.push_back(y);
    }
 
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
 
    nn = 0;
    mm = 0;
 
    while((nn < n) && (mm < n))
    {
        if (a[nn] < b[mm])
        {
            c++;
            nn++;
        } else if (a[nn] == b[mm])
        {
            nn++;
            mm++;
        } else
        {
            c--;
            mm++;
        }
        
        sol = max(sol, c);
    }
 
    while ((++nn) < n) c++;
    while ((++mm) < n) c--;
 
    sol = max(sol, c);
 
    cout << sol << "\n";
}