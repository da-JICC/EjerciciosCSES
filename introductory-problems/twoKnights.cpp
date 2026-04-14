#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(){
    ll k;
    cin >> k;

    for(ll i=1; i<=k; i++){
        ll total = i*i*(i*i - 1)/2 - 4*(i-1)*(i-2);
        cout << total << "\n";
    }

    return 0;
}