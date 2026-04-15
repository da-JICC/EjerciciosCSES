#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(){
    ll n, l=1, mod = 10*10*10*10*10*10*10*10*10 + 7;

    cin >> n;

    for(ll i=1; i<=n; i++){
        l*=2;
        l%=mod;
    }
    
    cout << l << '\n';
    
    return 0;
}