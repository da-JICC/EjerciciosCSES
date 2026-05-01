#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void backtracking(const vector<ll> pesos, int indice, ll &sumA, ll &sumB, ll &minimo){
    if(indice == (int)pesos.size()){
        minimo = min(minimo, abs(sumA - sumB));
        return;
    }

    sumA += pesos[indice];
    backtracking(pesos, indice+1, sumA, sumB, minimo);
    sumA -= pesos[indice];

    sumB += pesos[indice];
    backtracking(pesos, indice+1, sumA, sumB, minimo);
    sumB -= pesos[indice];
}


int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    ll peso;
    vector<ll> pesos;
    for(int i=0; i<n; i++){
        cin >> peso;
        pesos.push_back(peso);
    }

    ll sumA, sumB;
    sumA = sumB = 0;
    ll valor = 20*1e9;
    backtracking(pesos,0,sumA, sumB, valor);
    cout << valor << endl;
    return 0;
}




