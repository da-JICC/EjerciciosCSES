#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(){
    ll n;

    cin >> n;

    //Analisis previo
    if(n==2 or n==3){
        cout << "NO SOLUTION" << '\n';
        return 0;
    }

    ll valor = 2;

    while(valor<=n){
        cout << valor << " ";
        valor += 2;
    }
    
    valor = 1;

    while(valor<=n){
        cout << valor;
        if (valor + 1 < n){
            cout << " ";
        }
        valor += 2;
    }
    return 0;
}