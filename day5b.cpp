#include <bits/stdc++.h> 
using namespace std; 

typedef long long ll; 

vector<string> text; 

vector<pair<ll,ll>> extract(string& s) {
    stringstream ss; ss<<s; 
    string bin; ss>>bin;
    ll val; 
    vector<ll> ans; 
    while (ss>>val) {
        ans.push_back(val); 
    }
    vector<pair<ll,ll>> ans2; 
    for (int i=0; i<(int)ans.size(); ++i) {
        if (i%2==0) {
            ans2.push_back(make_pair(ans[i], ans[i]+ans[i+1]-1)); 
        }
    }
    return ans2; 
}

vector<ll> extract2(string& s) {
    vector<ll> ans; 
    stringstream ss;
    ss<<s; 
    ll val; 
    for (int i=0; i<3; ++i) {
        ss>>val; 
        ans.push_back(val); 
    }
    return ans; 
}

int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 

    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 

    string l; 
    while (getline(cin,l)) {
        text.push_back(l); 
    }
    
    vector<pair<ll,ll>> ranges=extract(text[0]); 
    vector<pair<ll,ll>> new_ranges; 

    int cnt=0; 
    for (string& s : text) {
        if ((int)s.size()>=4) {
            if (s.substr((int)s.size()-4, 4)=="map:") {
                ++cnt; 
                for (auto& x : new_ranges) {
                    ranges.push_back(x); 
                }
                new_ranges.clear(); 
                continue; 
            }
        }
        if (cnt) {
            vector<ll> data=extract2(s); 
            ll destination=data[0], source=data[1], r=data[2]; 
            for (auto it=ranges.begin(); it!=ranges.end(); ++it) {
                pair<ll,ll> cur=*it; 
                ll a=cur.first, b=cur.second; 
                if (a>=source&&b<=source+r-1) {
                    ranges.erase(it); --it; 
                    new_ranges.push_back(make_pair(destination+a-source, destination+b-source)); 
                    continue; 
                } 
                if (a>=source&&a<=source+r-1&&b>source+r-1) {
                    ranges.erase(it); --it; 
                    new_ranges.push_back(make_pair(destination+a-source,destination+r-1)); 
                    ranges.push_back(make_pair(source+r,b)); 
                    continue; 
                } 
                if (a<source&&b<=source+r-1&&b>=source) {
                    ranges.erase(it); --it; 
                    new_ranges.push_back(make_pair(destination, destination+b-source)); 
                    ranges.push_back(make_pair(a, source-1)); 
                    continue; 
                }
                if (a<source&&b>source+r-1) {
                    ranges.erase(it); --it; 
                    new_ranges.push_back(make_pair(destination, destination+r-1)); 
                    ranges.push_back(make_pair(a,source-1)); 
                    ranges.push_back(make_pair(source+r, b)); 
                    continue; 
                }
            }
        }
    }
    ll ans=LONG_LONG_MAX; 
    for (auto& x : ranges) {
        ans=min(ans, x.first); 
    }
    cout<<ans<<'\n'; 

    return 0; 
}