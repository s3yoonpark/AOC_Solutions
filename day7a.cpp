#include <bits/stdc++.h> 
using namespace std; 

typedef long long ll; 

string order="AKQJT987654321"; 
unordered_map<string,ll> mp; 

typedef long long ll; 

pair<string,ll> extract(string& s) {
    stringstream ss; 
    ss<<s; 
    pair<string,ll> ans; 
    ss>>ans.first; 
    ss>>ans.second; 
    return ans; 
}

int type(string s) {
    set<char> se(s.begin(), s.end()); 
    if (se.size()==1) {
        return 7; 
    }
    if (se.size()==2) {
        // four of a kind or full house 
        char a=*se.begin(), b=*++se.begin(); 
        if (count(s.begin(), s.end(), a)==4||count(s.begin(), s.end(), b)==4) {
            return 6; 
        } else {
            return 5; 
        }
    }
    if (se.size()==3) {
        // three of a kind or two pair 
        for (char c : se) {
            if (count(s.begin(), s.end(), c)==3) {
                return 4; 
            }
        }
        return 3; 
    }
    if (se.size()==4) {
        return 2; 
    }
    if (se.size()==5) {
        return 1; 
    }
}

bool cmp(const string& A, const string& B) {
    int ta=type(A), tb=type(B); 
    if (ta!=tb) return ta<tb; 
    for (int i=0; i<5; ++i) {
        char a=A[i], b=B[i]; 
        int inda=order.find(a), indb=order.find(b); 
        if (inda!=indb) return inda>indb; 
    }
}

int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 

    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 

    string line; 
    vector<string> hands; 
    while (getline(cin,line)) {
        string hand=extract(line).first; ll bid=extract(line).second; 
        mp[hand]=bid; 
        hands.push_back(hand); 
    }
    sort(hands.begin(), hands.end(), cmp); 
    ll ans=0; 
    for (int i=0; i<(int)hands.size(); ++i) {
        cout<<i+1<<' '<<hands[i]<<' '<<mp[hands[i]]<<' '<<type(hands[i])<<'\n'; 
        ans+=1LL*(i+1)*mp[hands[i]]; 
    }
    cout<<ans<<'\n'; 
    
}