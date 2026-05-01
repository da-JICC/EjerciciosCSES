#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll minimo(const vector<ll> pesos){
    ll minimo = 10*1e9;
    for(int mascara = 0; mascara < (1<<pesos.size()); mascara++){
        ll sumA, sumB;
        sumA = sumB = 0;
        for(int i=0; i<(int)pesos.size(); i++){
            if(mascara & (1<<i)){
                sumA += pesos[i];
            }
            else{
                sumB += pesos[i];
            } 
        }
        minimo = min(minimo, abs(sumA - sumB));
    }
    return minimo;
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
    ll valor = minimo(pesos);
    cout << valor << endl;
    return 0;
}




