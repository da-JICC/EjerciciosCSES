#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int n;
    cin >> n;

    vector<vector<bool>> usadosFila(200,vector<bool>(200,false));
    vector<vector<bool>> usadosCol(200,vector<bool>(200,false));
    vector<vector<int>> grid(n,vector<int>(n,0));

    for(int i=0; i<n; i++){
        //cout << "FILA " << i <<endl;
        for(int j=0; j<n; j++){
            if(i<=j){
                // Buscar mínimo disponible
                //cout << "COL " << j <<endl;
                bool encontrado = false;
                for(int k=0; encontrado==false; k++){
                    if (!usadosFila[i][k] and !usadosCol[j][k]){
                        //cout << k << " no ha sido usado ni en la fila " << i << " ni en la col " << j << endl;
                        usadosFila[i][k]=true;
                        usadosFila[j][k]=true;
                        usadosCol[j][k]=true;
                        usadosCol[i][k]=true;
                        grid[i][j]=k;
                        grid[j][i]=k;
                        encontrado=false;
                        break;
                    }
                    else{
                        //cout << k << " ha sido usado en la fila " << i << " o en la col " << j << endl;
                    }
                }
            }
        }
    }

    // print
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }


    return 0;

}