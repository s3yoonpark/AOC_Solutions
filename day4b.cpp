#include <bits/stdc++.h> 
using namespace std; 

typedef long long ll; 

int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 

    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout); 

    string t;
    vector<string> text={""}; 
    while (getline(cin,t)) {
        text.push_back(t); 
    }
    vector<int> cnt((int)text.size()+1,1); cnt[0]=0; 
    for (int i=1; i<(int)text.size(); ++i) {
        string s=text[i];
        s=s.substr(s.find(':')+2, (int)s.size()-(int)s.find(':')-2);  
        string a=s.substr(0,s.find('|')-1), b=s.substr(s.find('|')+2,(int)s.size()-s.find('|')-2); 
        stringstream ss; 
        set<int> win, num; 
        ss.clear(); ss<<a; 
        int val; 
        while (ss>>val) {
            win.insert(val); 
        }
        ss.clear(); ss<<b; 
        while (ss>>val) {
            num.insert(val); 
        }
        int c=0; 
        for (int i : win) {
            if (num.count(i)) {
                ++c; 
            }
        }
        for (int j=i+1; j<=i+c; ++j) {
            cnt[j]+=cnt[i]; 
        }
    }
    int sum=0; 
    for (int i=1; i<(int)text.size(); ++i) {
        sum+=cnt[i]; 
    }
    cout<<sum<<'\n'; 

    return 0;   
}