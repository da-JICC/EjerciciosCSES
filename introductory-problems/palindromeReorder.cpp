#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s;
    cin >> s;
    map <char,ll> letras;
    

    for(char c : s){
        letras[c]++;
    }
    
    ll impares = 0, charImpar=' ';

    for(auto it = letras.begin(); it != letras.end(); it++){
        if (it->second%2!=0){
            impares++;
            charImpar = it->first;
        }
    }

    if(impares>1){
        cout << "NO SOLUTION" << '\n';
        return 0;
    }

    string palindromo = "";

    for(auto it = letras.begin(); it != letras.end(); it++){
        if (it->second%2==0){
            palindromo += string((it->second)/2,it->first);
        }
    }

    string palindromo2 = palindromo;
    reverse(palindromo2.begin(),palindromo2.end());

    palindromo += string(letras[charImpar],charImpar) + palindromo2;
    
    cout << palindromo << '\n';
    return 0;
}