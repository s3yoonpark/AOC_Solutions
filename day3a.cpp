#include <bits/stdc++.h> 
using namespace std; 

typedef long long ll; 

vector<string> text; 
vector<vector<bool>> vis; 

string exp(int i, int j) {
    string res=""; 
    for (int x=j; x<(int)text[0].size(); ++x) {
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
            if (!vis[i][j]) {
                string d=exp(i, j); 
                if ((int)d.size()) {
                    // left upper corner (i-1, j-1) 
                    // right upper corner (i-1, j+d.size())
                    bool found=0; 
                    if (i-1>=0) {
                        for (int x=j-1; x<=j+(int)d.size()&&!found; ++x) {
                            if (x>=0&&x<(int)text[0].size()) {
                                if (symbol(text[i-1][x])) {
                                    found=1; 
                                }
                            }
                        }
                    }
                    if (i+1<(int)text.size()) {
                        for (int x=j-1; x<=j+(int)d.size()&&!found; ++x) {
                            if (x>=0&&x<(int)text[0].size()) {
                                if (symbol(text[i+1][x])) {
                                    found=1; 
                                }
                            }
                        }
                    }
                    if (j-1>=0) {
                        if (symbol(text[i][j-1])) {
                            found=1; 
                        }
                    }
                    if (j+(int)d.size()<(int)text[0].size()) {
                        if (symbol(text[i][j+(int)d.size()])) {
                            found=1; 
                        }
                    }
                    if (found) {
                        sum+=stoll(d); 
                    }
                }
            }
        }
    }
    cout<<sum<<'\n'; 

    return 0; 
}