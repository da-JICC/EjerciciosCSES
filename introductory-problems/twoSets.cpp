#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(){
    ll n;
    cin >> n;

    ll suma = 0, total = n*(n+1)/2;

    if(total%2!=0){
        cout << "NO" << '\n';
        return 0;
    }

    cout << "YES" << '\n';

    set <ll> A, B;


    for(ll i = n; i>=1; i--){
        if(suma + i <= total/2){
            suma += i;
            A.insert(i);
        }
        else{
            B.insert(i);
        }
    }

    cout << A.size();
    cout << '\n';

    ll sumA=0, sumB=0;
    for(auto it = A.begin(); it!=A.end(); it++){
        cout << *it;
        sumA+=*it;
        if(it!=prev(A.end())){
            cout << " ";
        }
    }
    cout << '\n';
     cout << B.size();
    cout << '\n';
    for(auto it = B.begin(); it!=B.end(); it++){
        cout << *it;
        sumB+=*it;
        if(it!=prev(B.end())){
            cout << " ";
        }

    }
    cout << '\n';


    

    return 0;
}