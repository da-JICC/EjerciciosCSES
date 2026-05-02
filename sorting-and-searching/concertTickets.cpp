#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m;
    cin >> n >> m;

    multiset<ll> tickets;
    vector<ll> clientes(m,0);

    ll ticket;
    for(ll i = 0; i<n; i++){
        cin >> ticket;
        tickets.insert(ticket);
    }

    for(ll i = 0; i<m; i++){
        cin >> clientes[i];
    }

    for(ll i=0; i<m; i++){
        auto it = tickets.upper_bound(clientes[i]);
        if(it!=tickets.begin()){
            cout << *prev(it) << endl;
            tickets.erase(prev(it));
        }
        else{
            cout << -1 << endl;
        }
    }

    return 0;
}