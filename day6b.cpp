#include <bits/stdc++.h> 
using namespace std; 

typedef long long ll; 

ll extract(string& s) {
    stringstream ss; ss<<s; 
    string bin; ss>>bin; 
    ll ans; ss>>ans; 
    return ans; 
}

int main() {
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    
    string l; 
    getline(cin,l); 
    ll time=extract(l); 
    getline(cin,l); 
    ll dist=extract(l); 

    ll ans=0; 
    for (ll j=0; j<=time; ++j) {
        if (j*(time-j) > dist) {
            ++ans; 
        }
    }
       
    cout<<ans<<'\n'; 

    return 0; 
}