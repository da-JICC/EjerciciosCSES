#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<char>> inicial(n, vector<char>(m, ' '));
    vector<vector<char>> final(n, vector<char>(m, ' '));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> inicial[i][j];
        }
    }

    char letra = 'A';
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            letra = 'A';
            while(letra < 'E'){
                if(letra == inicial[i][j]){
                    letra++;
                    continue;
                }
                if(i-1 >= 0 and letra == final[i-1][j]){
                    letra++;
                    continue;
                }
                if(j-1 >= 0 and letra == final[i][j-1]){
                    letra++;
                    continue;
                }
                break;
            }
            final[i][j]=letra;
        }
    }


    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << final[i][j];
        }
        cout << endl;
    }


    return 0;
}