#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(){
    string cadena;
    cin >> cadena;
    ll contador = 0, cmax = 0;
    char letraCadena = cadena[0];
    for(char c : cadena){
        if (c == letraCadena){
            contador++;
        }
        else{
            letraCadena = c;
            cmax = max(cmax, contador);
            contador = 1;
        }
    }
    cmax = max(cmax, contador);
    cout << cmax << '\n';



    return 0;
}