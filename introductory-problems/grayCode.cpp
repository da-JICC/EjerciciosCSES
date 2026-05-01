#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

void grayCode(int n, vector<string> &conjuntoSolucion);

int main(){
    int n;
    cin >> n;

    string numeroBinario = "";
    for(int i=0; i<n; i++){
        numeroBinario += "0";
    }


    vector<string> numeros((1<<n),numeroBinario);
    grayCode(n, numeros);

    for(int i=0; i<(1<<n); i++){
        cout << numeros[i] << endl;
    }
    return 0;
}

void grayCode(int n, vector<string> &conjuntoSolucion){
    //Recorrer cada bit
    for(int i=0; i<n; i++){
        //cout << "--------------------Recorriendo bit " << i << "------------------" << endl;
        //Recorrer cada elemento del codigo Gray (2^n)
        int mitad = (1<<i);
        int acumMitad = 0;
        int total = (1<<(i+1));
        int acumTotal = 0;
        bool sumar = true;
        for(int j=0; j<(1<<n); j++){
            //cout << "Recorriendo bit " << i << " de elemento " << j << ": "; 
            if (acumMitad < mitad){
                //cout << "sumamos 0" << endl;
                acumMitad++;
            }
            else{
                if(acumTotal == total){
                    acumTotal = 0;
                    if(sumar){
                        sumar=false;
                    }
                    else{
                        sumar=true;
                    }
                }
                if(sumar){
                    conjuntoSolucion[j][n-1-i]='1';
                    //cout << "colocamos 1 en posicion i de numero j " << endl;
                }
                else{
                    //cout << "sumamos 0" << endl;
                }
                acumTotal++;
            }
        }
    }
    return;
}