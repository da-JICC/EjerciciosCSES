#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct pila{
    stack<ll> p;
    int indice;
};


void armarTorre(ll n, pila &pilaObjetivo, pila &pilaActual, pila &pilaAux, queue<pair<int,int>> &movs){
    if(n == 0){
        return;
    }
    
    //Mover torre n-1 a aux
    armarTorre(n-1, pilaAux, pilaActual, pilaObjetivo, movs);
    ll disco = pilaActual.p.top();

    //Mover base a objetivo
    pilaActual.p.pop();
    pilaObjetivo.p.push(disco);

    //Registrar movimiento
    pair<int,int> movimiento;
    movimiento.first = pilaActual.indice;
    movimiento.second = pilaObjetivo.indice;
    movs.push(movimiento);

    //Mover torre n-1 a objetivo
    armarTorre(n-1, pilaObjetivo, pilaAux, pilaActual, movs);
}

void crearTorreInicial(ll n, stack<ll> &pila){
    for(ll i=n; i>0; i--){
        pila.push(i);
    }
    return;
}


int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    
    //Variables necesarias
    pila inicial, aux, objetivo;
    queue<pair<int,int>> movs;
    inicial.indice = 1;
    aux.indice = 2;
    objetivo.indice = 3;

    //Crear torre
    crearTorreInicial(n,inicial.p);

    //Resolver
    armarTorre(n,objetivo,inicial,aux, movs);

    //Print
    cout << movs.size() << endl;
    while(!movs.empty()){
        cout << movs.front().first << " " << movs.front().second << endl;
        movs.pop();
    }
    return 0;
}