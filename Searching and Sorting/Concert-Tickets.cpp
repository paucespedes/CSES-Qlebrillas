#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pi;

ll tt, n, m, nn, mm, y;
char c;
string s;
vl a;
vl b;

int searchTicket(ll x, vl &array){
    int ai = 0, bf = n-1;
    while (ai <= bf) {
        int k = (ai+bf)/2;
        if (array[k] == x) {
            return k;
        }
        if (array[k] < x) ai = k+1;
        else bf = k-1;
    }

    if(array[ai] <= x)
        return ai;
    else if(ai - 1 >= 0 && array[ai - 1] <= x)
        return ai - 1;
    return -1;
}
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    cin >> n >> m;
    nn = n;

    for(;nn--;){
        cin >> y;
        a.push_back(y);
    }

    sort(a.begin(), a.end());

    for(;m--;){
        cin >> y;
        int idx = searchTicket(y, a);
        ll sol = -1;
        if(idx != -1){
            sol = a[idx];
            a.erase(a.begin() + idx);
        }
        cout << sol << "\n";
    }    

    return 0;
}