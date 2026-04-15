#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main(){
    ll n, zeros = 0;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    ll actual;
    for(ll i=5; i<=n; i+=5){
        actual = i;
        while(actual%5==0 and actual!=0){
            actual /= 5;
            zeros++;
        }
    }
    
    cout << zeros << '\n';
    
    return 0;
}