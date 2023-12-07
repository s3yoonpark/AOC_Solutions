#include <bits/stdc++.h> 
using namespace std; 

typedef long long ll; 

vector<string> digits={"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"}; 

int main() {
	ios_base::sync_with_stdio(0); 
	cin.tie(0); 

	freopen("input.txt", "r", stdin); 
	freopen("output.txt", "w", stdout); 

	string s; 

	ll sum=0; 

	while (cin>>s) {
		string t=""; 
		for (int i=0; i<s.size(); ++i) {
			if (isdigit(s[i])) {
				t+=s[i]; 
				break; 
			}
			bool found=0; 
			for (int j=0; j<digits.size(); ++j) {
				string d=digits[j]; 
				int n=d.size(); 
				if (i+n<=s.size()) {
					if (s.substr(i, n)==d) {
						t+=to_string(j+1); 
						found=1; 
						break; 
					}
				}
			}
			if (found) break; 
		}
		for (int i=s.size()-1; i>=0; --i) {
			if (isdigit(s[i])) {
				t+=s[i]; 
				break; 
			}
			bool found=0; 
			for (int j=0; j<digits.size(); ++j) {
				string d=digits[j]; 
				int n=d.size(); 
				if (i-n+1>=0) {
					if (s.substr(i-n+1, n)==d) {
						t+=to_string(j+1); 
						found=1; 
						break; 
					}
				}
			}
			if (found) break; 
		}
		sum+=stoll(t); 
		cout<<t<<'\n'; 
	}

	cout<<sum<<'\n'; 

	return 0; 
}