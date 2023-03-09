#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pi;

ll tt, n, m, k, nn, mm, x, sol;
char c;
string s;
vl a;
vl b;
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    cin >> n >> m >> k;
    nn = n;
    mm = m;
    sol = 0;

    for(;nn--;){
        cin >> x;
        a.push_back(x);
    }

    for(;mm--;){
        cin >> x;
        b.push_back(x);
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int bi = 0;
    for(int i = 0; i < n && bi < m; i++){
        while(b[bi] < a[i] - k && bi < m)
            bi++;
        if(bi < m && b[bi] <= a[i] + k){
            sol++;
            bi++;
        }
    }

    cout << sol << "\n";

    return 0;
}