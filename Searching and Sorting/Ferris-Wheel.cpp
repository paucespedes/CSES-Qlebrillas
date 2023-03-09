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
 
    cin >> n >> m;
    nn = n;
    sol = 0;

    for(;nn--;){
        cin >> x;
        a.push_back(x);
    }

    sort(a.begin(), a.end());

    int idxi = 0;
    int idxf = n-1;
    while(idxi < idxf){
        if(a[idxf] + a[idxi] > m){
            idxf--;
        }
        else{
            idxi++;
            idxf--;
        }
        sol++;
    }
    
    if(idxi == idxf)
        sol++;

    cout << sol << "\n";

    return 0;
}