#include <bits/stdc++.h>

using namespace std;

/*
int factorial(int n){
    if(n==1){
        return 1;
    }
    return n*factorial(n-1);
}
*/

//Teorico
/*
int contarCombinaciones(const map<char,int> &letras, int largoPalabra){
    int letrasDistintas = 0;
    int factorDivision = 1;
    int combinacionesBase = factorial(largoPalabra);
    for(auto it = letras.begin(); it!= letras.end(); it++){
        letrasDistintas++;
        factorDivision*=factorial(it->second);
    }

    return combinacionesBase/factorDivision;
    return 0;
}
*/

void generarPalabras(int n, map<char,int> &letras, set<string> &palabrasFormadas, string &palabraFormada, int indice=0){
    if(indice == n){
        palabrasFormadas.insert(palabraFormada);
        return;
    }

    for(auto it = letras.begin(); it != letras.end(); it++){
        string palabraActual = palabraFormada;
        if(it->second>0){
            palabraFormada += it->first;
            it->second--;
            generarPalabras(n,letras,palabrasFormadas,palabraFormada,indice+1);
            it->second++;
            palabraFormada = palabraActual;
        }
    }
    return;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string palabra;
    cin >> palabra;

    map<char,int> letras;

    for(char c: palabra){
        letras[c]++;
    }
    set<string> palabras;
    string palabraActual = "";
    generarPalabras(palabra.size(), letras, palabras, palabraActual);
    cout << palabras.size() << endl;
    for(string elem : palabras){
        cout << elem << endl;
    }
    return 0;
}




