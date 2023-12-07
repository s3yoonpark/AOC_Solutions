#include <bits/stdc++.h> 
using namespace std; 

vector<int> extract(string& s) {
    stringstream ss; ss<<s; 
    string bin; ss>>bin; 
    vector<int> ans(4); 
    for (int i=0; i<4; ++i) {
        ss>>ans[i]; 
    }
    return ans; 
}

int main() {
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    
    string l; 
    getline(cin,l); 
    vector<int> time=extract(l); 
    getline(cin,l); 
    vector<int> dist=extract(l); 

    vector<int> ans(4,0); 
    int prod=1; 
    for (int i=0; i<4; ++i) {
        for (int j=0; j<=time[i]; ++j) {
            if (j*(time[i]-j) > dist[i]) {
                ++ans[i]; 
            }
        }
        prod*=ans[i]; 
    }
    cout<<prod<<'\n'; 

    return 0; 
}