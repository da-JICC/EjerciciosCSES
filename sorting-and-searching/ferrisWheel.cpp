#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,x;
    cin >> n >> x;
    vector<ll> pesos(n,0);
    for(ll i=0; i<n; i++){
        cin >> pesos[i];
    }
    
    sort(pesos.begin(), pesos.end());

    ll i=0, j=n-1, gondolas=0;
    while(i!=j and i<j){
        //Si caben 2 niños
        if(pesos[i]+pesos[j]<=x){
            gondolas++;
            i++;
        }
        //Si no caben sí o sí se necesita 1 góndola para el más pesado
        else{
            gondolas++;
        }
        j--;
    }

    if(i == j){
        gondolas++;
    }


    cout << gondolas << endl;

    return 0;

}