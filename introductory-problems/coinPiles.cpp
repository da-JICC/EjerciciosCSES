#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main(){
    ll n;
    cin >> n;

    for(ll i=0; i<n; i++){
        ll m,n,x,y;
        cin >> m >> n;
        x = n - (2*n-m)*2/3;
        y = (2*n - m)/3;
        if (x>=0 and y>=0 and (2*n-m)%3==0){
            cout << "YES" << '\n';
        }
        else{
            cout << "NO" << '\n';
        }
    }

    
    
    return 0;
}