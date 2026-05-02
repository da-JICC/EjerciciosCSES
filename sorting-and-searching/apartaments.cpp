#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,m,k;
    cin >> n >> m >> k;

    vector<ll> personas(n,0);
    vector<ll> dptos(m,0);

    for(int i=0; i<n; i++){
        cin >> personas[i];
    }
    for(int i=0; i<m; i++){
        cin >> dptos[i];
    }


    sort(personas.begin(), personas.end());
    sort(dptos.begin(), dptos.end());

    //Recorrer personas
    int j=0, cont=0;
    for(int i=0; i<n; i++){
        //buscar dptos
        while(j!=m){
            if(personas[i]-k > dptos[j]){
                j++;
                continue;
            }
            if(personas[i]-k <= dptos[j] and dptos[j] <= personas[i]+k){
                j++;
                cont++;
                break;
            }
            if(dptos[j] > personas[i]+k){
                break;
            }
        }
    }
    
    cout << cont << endl;


    return 0;
}




