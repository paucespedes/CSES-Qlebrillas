#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

ll tt, n, m, q = 1;
char c;
string s;
vi a;
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    cin >> tt;
    for(;tt--;){
        cin >> n;
        a.push_back(n);
    }

    sort(a.begin(), a.end());
    for(int i = 0; i < a.size() - 1; i++){
        if(a[i] != a[i+1])
            q++;
    }

    cout << q << "\n";

    return 0;
}