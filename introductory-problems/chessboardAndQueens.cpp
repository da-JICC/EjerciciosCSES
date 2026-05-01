#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

struct tablero{
    vector<bool> fila = vector<bool>(8,false);
    vector<bool> columna = vector<bool>(8,false);
    vector<bool> diag1 = vector<bool>(30,false);
    vector<bool> diag2 = vector<bool>(30,false);
};

void procesarInput(vector<vector<bool>> &reservados){
    for(int i=7; i>=0; i--){
        for(int j=0; j<8; j++){
            char elem;
            cin >> elem;
            if (elem == '*'){
                reservados[i][j]=true;
            }
        }
    }
}

void backtracking(tablero &celdasOcupadas, const vector<vector<bool>> &reservados, ll &totalCombinaciones, int fila=0, int reinasActuales=0){

    if(reinasActuales == 8){
        totalCombinaciones++;
        return;
    }

    for(int filaActual = fila; filaActual<8; filaActual++){
        for(int columnaActual = 0; columnaActual<8; columnaActual++){
            if(celdasOcupadas.fila[filaActual] or celdasOcupadas.columna[columnaActual] or celdasOcupadas.diag1[7 + filaActual - columnaActual] or celdasOcupadas.diag2[filaActual + columnaActual]){
                continue;
            }
            else{
                if(!reservados[filaActual][columnaActual]){

                    celdasOcupadas.fila[filaActual] = true;
                    celdasOcupadas.columna[columnaActual] = true;
                    celdasOcupadas.diag1[7 + filaActual - columnaActual] = true;
                    celdasOcupadas.diag2[filaActual + columnaActual] = true;

                    backtracking(celdasOcupadas, reservados, totalCombinaciones, filaActual + 1, reinasActuales + 1);

                    celdasOcupadas.fila[filaActual] = false;
                    celdasOcupadas.columna[columnaActual] = false;
                    celdasOcupadas.diag1[7 + filaActual - columnaActual] = false;
                    celdasOcupadas.diag2[filaActual + columnaActual] = false;
                }
            }
        }
    }


    return;    
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<bool>> reservados(8,vector<bool>(8,false));
    ll numCombinaciones=0;

    procesarInput(reservados);

    tablero tabla;

    backtracking(tabla, reservados, numCombinaciones);
    cout << numCombinaciones << endl;
    return 0;
}