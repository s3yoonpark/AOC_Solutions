#include <bits/stdc++.h> 
using namespace std; 

typedef long long ll; 

int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 

    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout); 

    string s;
    ll sum=0; 
    while (getline(cin,s)) {
        s=s.substr(s.find(':')+2, (int)s.size()-s.find(':')-2); 
        string a=s.substr(0,s.find('|')-1), b=s.substr(s.find('|')+2,(int)s.size()-s.find('|')-2); 
        set<int> win, num; 
        stringstream iss; iss<<a; 
        int val; 
        while (iss>>val) {
            win.insert(val); 
        }
        iss.clear(); iss<<b;  
        while (iss>>val) {     
            num.insert(val); 
        }
        int cnt=0; 
        for (int i : win) {
            if (num.count(i)) {
                ++cnt; 
            }
        }
        sum+=pow(2,cnt-1); 
    }
    cout<<sum<<'\n'; 

    return 0; 
}