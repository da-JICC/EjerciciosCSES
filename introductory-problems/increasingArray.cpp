#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(){
    ll n, movimientos = 0;
    cin >> n;
    vector <ll> numeros(n);

    for(ll i = 0; i<n; i++){
        cin >> numeros[i];
        if(i != 0 and numeros[i] < numeros[i-1]){
            movimientos += numeros[i-1] - numeros[i];
            numeros[i] += numeros[i-1] - numeros[i];
        }
    }

    cout << movimientos << '\n';

    return 0;
}