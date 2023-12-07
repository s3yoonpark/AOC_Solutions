#include <bits/stdc++.h> 
using namespace std; 

typedef long long ll; 

vector<string> text; 

vector<ll> gen(string& s) {
    stringstream ss; 
    ss<<s; 
    string bin; 
    ss>>bin; 
    ll val; 
    vector<ll> ans; 
    while (ss>>val) {
        ans.push_back(val); 
    }
    return ans; 
}

int main() {
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 

    string l; 
    while (getline(cin,l)) {
        text.push_back(l); 
    }
    vector<ll> seeds=gen(text[0]); 
    vector<ll> soil((int)seeds.size(),-1); 
    vector<ll> fertilizer((int)seeds.size(),-1); 
    vector<ll> water((int)seeds.size(),-1); 
    vector<ll> light((int)seeds.size(),-1); 
    vector<ll> temperature((int)seeds.size(),-1); 
    vector<ll> humidity((int)seeds.size(),-1); 
    vector<ll> location((int)seeds.size(),-1); 

    int cnt=0; 
    for (string& line : text) {
        if ((int)line.size()>=4) {
            if (line.substr((int)line.size()-4, 4)=="map:") {
                ++cnt; 
                continue; 
            }
        }
        stringstream ss; ss<<line; 
        ll a,b,c; 
        ss>>a>>b>>c; 
        if (cnt==1) {
            for (int i=0; i<(int)seeds.size(); ++i) {
                if (soil[i]!=-1) continue; 
                if (b<=seeds[i]&&seeds[i]<b+c) {
                    soil[i]=seeds[i]-b+a; 
                }
            }
        } else if (cnt==2) {
            for (int i=0; i<(int)seeds.size(); ++i) {
                if (soil[i]==-1) {
                    soil[i]=seeds[i]; 
                }
            }
            for (int i=0; i<(int)seeds.size(); ++i) {
                if (fertilizer[i]!=-1) continue; 
                if (b<=soil[i]&&soil[i]<b+c) {
                    fertilizer[i]=soil[i]-b+a; 
                }
            }
        } else if (cnt==3) {
            for (int i=0; i<(int)seeds.size(); ++i) {
                if (fertilizer[i]==-1) {
                    fertilizer[i]=soil[i]; 
                }
            }
            for (int i=0; i<(int)seeds.size(); ++i) {
                if (water[i]!=-1) continue; 
                if (b<=fertilizer[i]&&fertilizer[i]<b+c) {
                    water[i]=fertilizer[i]-b+a; 
                }
            }
        } else if (cnt==4) {
            for (int i=0; i<(int)seeds.size(); ++i) {
                if (water[i]==-1) {
                    water[i]=fertilizer[i]; 
                }
            }
            for (int i=0; i<(int)seeds.size(); ++i) {
                if (light[i]!=-1) continue; 
                if (b<=water[i]&&water[i]<b+c) {
                    light[i]=water[i]-b+a; 
                }
            }
        } else if (cnt==5) {
            for (int i=0; i<(int)seeds.size(); ++i) {
                if (light[i]==-1) {
                    light[i]=water[i]; 
                }
            }
            for (int i=0; i<(int)seeds.size(); ++i) {
                if (temperature[i]!=-1) continue; 
                if (b<=light[i]&&light[i]<b+c) {
                    temperature[i]=light[i]-b+a; 
                }
            }
        } else if (cnt==6) {
            for (int i=0; i<(int)seeds.size(); ++i) {
                if (temperature[i]==-1) {
                    temperature[i]=light[i]; 
                }
            }
            for (int i=0; i<(int)seeds.size(); ++i) {
                if (humidity[i]!=-1) continue; 
                if (b<=temperature[i]&&temperature[i]<b+c) {
                    humidity[i]=temperature[i]-b+a; 
                }
            }
        } else if (cnt==7) {
            for (int i=0; i<(int)seeds.size(); ++i) {
                if (humidity[i]==-1) {
                    humidity[i]=temperature[i]; 
                }
            }
            for (int i=0; i<(int)seeds.size(); ++i) {
                if (location[i]!=-1) continue; 
                if (b<=humidity[i]&&humidity[i]<b+c) {
                    location[i]=humidity[i]-b+a; 
                }
            }
        }
    }

    for (int i=0; i<(int)seeds.size(); ++i) {
        if (location[i]==-1) {
            location[i]=humidity[i]; 
        }
    }

    ll ans=LONG_LONG_MAX; 
    for (ll i : location) {
        ans=min(ans,i); 
    }
    cout<<ans<<'\n'; 

    return 0; 
}