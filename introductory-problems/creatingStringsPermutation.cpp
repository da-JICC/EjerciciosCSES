#include <bits/stdc++.h>

using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string palabra;
    cin >> palabra;

    sort(palabra.begin(), palabra.end());
    set <string> palabras;
    palabras.insert(palabra);
    while(next_permutation(palabra.begin(), palabra.end())){
        palabras.insert(palabra);
    }
    
    cout << palabras.size() << endl;
    for(auto elem : palabras){
        cout << elem << endl;
    }

    return 0;
}




