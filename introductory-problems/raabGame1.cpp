#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin >> tests;

    int n, a, b;
    for(int i=0; i<tests; i++){
        cin >> n >> a >> b;

        //No pueden sumar más de n puntos | ganador no puede ganar con n puntos (n a 0)
        if(a + b > n or (max(a,b) > n-1 and min(a,b) < 1) or (max(a,b) > 0 and min(a,b) < 1)){
            cout << "NO" << endl;
            continue;
        }

       

        stack<int> wCartas;
        stack<int> lCartas;

        vector<int> wJugadas;
        vector<int> lJugadas;
        for(int j=n; j>=1; j--){
            wCartas.push(j);
            lCartas.push(j);
        }

        int ganador = max(a,b), perdedor = min(a,b);

        if(perdedor != 1){
            perdedor--;
            ganador--;
        }
        else{
            perdedor = 0;
        }
        
        int w, l;

        
        // Zona ganador construcción
        int sobrante = wCartas.top();
        wCartas.pop();
        //cout << "Parte 1:" << endl;
        for(int j=0; j<ganador; j++){
            w = wCartas.top();
            l = lCartas.top();
            //cout << "w = " << w << " l = " << l << endl;
            wCartas.pop();
            lCartas.pop();
            wJugadas.push_back(w);
            lJugadas.push_back(l);
        }
        wJugadas.push_back(sobrante);
        l = lCartas.top();
        lCartas.pop();
        lJugadas.push_back(l);
        //cout << "w = " << sobrante << " l = " << l << endl;

        //cout << "Parte 2:" << endl;
        // Zona perdedor construcción
        if(!lCartas.empty() and !wCartas.empty()){
            sobrante = lCartas.top();
            lCartas.pop();
            for(int j=0; j<perdedor; j++){
                w = wCartas.top();
                l = lCartas.top();
                wCartas.pop();
                lCartas.pop();
                //cout << "w = " << w << " l = " << l << endl;
                wJugadas.push_back(w);
                lJugadas.push_back(l);
            }
            
            lJugadas.push_back(sobrante);
            w = wCartas.top(); 
            wCartas.pop();
            wJugadas.push_back(w);
        }
        //cout << "w = " << w << " l = " << sobrante << endl;

        //cout << "Parte 3:" << endl;
        // Zona empate construcción
        while(!lCartas.empty() and !wCartas.empty()){
            w = wCartas.top();
            l = lCartas.top();
            //cout << "w = " << w << " l = " << l << endl;
            wCartas.pop();
            lCartas.pop();
            wJugadas.push_back(w);
            lJugadas.push_back(l);
        }

        // Print 
        cout << "YES" << endl;
        if(a>b){
            for(int num : wJugadas){
                cout << num << " ";
            }
            cout << endl;
            for(int num : lJugadas){
                cout << num << " ";
            }
            cout << endl;
        }
        else{
            for(int num : lJugadas){
                cout << num << " ";
            }
            cout << endl;
            for(int num : wJugadas){
                cout << num << " ";
            }
            cout << endl;
        }

    }



    return 0;
}