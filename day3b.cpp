#include <bits/stdc++.h> 
using namespace std; 

typedef long long ll; 

vector<string> text; 
vector<vector<bool>> vis; 

string exp(int i, int j) {
    string res=""; 
    int ind=j; 
    for (int x=j; x>=0; --x) {
        if (isdigit(text[i][x])) {
            ind=x; 
        } else {
            break; 
        }
    }
    for (int x=ind; x<(int)text[0].size(); ++x) {
        if (isdigit(text[i][x])) {
            vis[i][x]=1; 
            res+=text[i][x]; 
        } else {
            break; 
        }
    }
    return res; 
}

bool symbol(char c) {
    return c!='.' && !isdigit(c); 
}

int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 

    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 

    ll sum=0; 

    string s; 
    while (getline(cin,s)) {
        text.push_back(s); 
    }
    vis = vector<vector<bool>>((int)text.size(), vector<bool>((int)text[0].size(), false)); 
    for (int i=0; i<(int)text.size(); ++i) {
        for (int j=0; j<(int)text[0].size(); ++j) {
            if (text[i][j]=='*') {
                int cnt=0; 
                vector<int> l; 
                    for (pair<int,int> x : vector<pair<int,int>>{{i,j-1}, {i,j+1}, {i-1,j-1}, {i-1,j}, {i-1,j+1}, {i+1,j-1}, {i+1,j}, {i+1,j+1}}) {
                    if (x.first>=0&&x.first<(int)text.size()&&x.second>=0&&x.second<(int)text[0].size()) {
                        if (isdigit(text[x.first][x.second])&&!vis[x.first][x.second]) {
                            l.push_back(stoi(exp(x.first, x.second))); 
                        }
                    }
                }
                if (l.size()==2) {
                    sum+=1LL*l[0]*l[1]; 
                }
            }
        }
    }
    cout<<sum<<'\n'; 

    return 0; 
}