#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(){
    ll t;
    cin >> t;
    for(ll i=0; i<t; i++){
        ll x,y,res=0;
        cin >> y >> x;

        if(y >= x){

            res = (y-1)*(y-1);
            
            if(y%2==0){
                res += 2*y - x;
            }
            else{
                res += x;
            }

        }
        else{
            res = (x-1)*(x-1);

            if(x%2==0){
                res += y;
            }
            else{
                res += 2*x - y;
            }
        }
        cout << res << '\n';
    }


    return 0;
}