#include <bits/stdc++.h> 
using namespace std; 

typedef long long ll; 

int main() {
	ios_base::sync_with_stdio(0); 
	cin.tie(0); 

	freopen("input.txt", "r", stdin); 
	freopen("output.txt", "w", stdout); 

	string s; 

	ll sum=0; 

	while (cin>>s) {
		string t=""; 
		for (char c : s) {
			if (isdigit(c)) {
				t+=c; 
				break; 
			}
		}
		for (int i=s.size()-1; i>=0; --i) {
			if (isdigit(s[i])) {
				t+=s[i]; 
				break; 
			}
		}
		sum+=stoll(t); 
	}

	cout<<sum<<'\n'; 

	return 0; 
}