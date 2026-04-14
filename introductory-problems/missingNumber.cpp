#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main(){

    ll n;
    cin >> n;
    vector<ll> numeros(n-1);

    for(ll i = 0; i<n-1; i++){
        cin >> numeros[i];
    }

    sort(numeros.begin(),numeros.end());

    ll numActual = 1;

    for(ll i = 1; i<=n; i++){
        if(numeros[i - 1] != numActual++){
            cout << i << '\n';
            break;
        }
    }


    return 0;
}