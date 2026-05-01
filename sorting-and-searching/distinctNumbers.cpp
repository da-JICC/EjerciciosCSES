#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    map<ll,ll> numeros;

    for(int i=0; i<n; i++){
        ll numero;
        cin >> numero;
        numeros[numero]++;
    }

    cout << numeros.size() << endl;
}




