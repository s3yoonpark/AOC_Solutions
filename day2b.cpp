#include <bits/stdc++.h> 
using namespace std; 

typedef long long ll; 

int main() {

	freopen("input.txt", "r", stdin); 
	freopen("output.txt", "w", stdout); 

	string s; 
	ll sum=0; 
	int cnt=0; 
	while (getline(cin, s)) {
		int min_red=0, min_blue=0, min_green=0; 
		s+=';'; 
		++cnt; 
		while (s.find(';')!=-1) {
			int red=12, green=13, blue=14; 
			int ind=s.find(';'); 
			string t=s.substr(0, ind+1); 
			for (int i=0; i<t.size(); ++i) {
				if (t[i]==',' || t[i]==';') {
					if (t[i-1]=='d') {
						// red
						string d=""; 
						for (int j=i-5; j>=0; --j) {
							if (isdigit(t[j])) {
								d+=t[j]; 
							} else {
								break; 
							}
						}
						reverse(d.begin(), d.end()); 
						min_red=max(min_red, stoi(d)); 
					}
					if (t[i-1]=='e') {
						// blue 
						string d=""; 
						for (int j=i-6; j>=0; --j) {
							if (isdigit(t[j])) {
								d+=t[j]; 
							} else {
								break; 
							}
						}
						reverse(d.begin(), d.end()); 
						min_blue=max(min_blue, stoi(d)); 
					}
					if (t[i-1]=='n') {
						// green 
						string d=""; 
						for (int j=i-7; j>=0; --j) {
							if (isdigit(t[j])) {
								d+=t[j]; 
							} else {
								break; 
							}
						}
						reverse(d.begin(), d.end()); 
						min_green=max(min_green, stoi(d)); 
					}
				}
			}
            if (ind+1>s.size()-1) break; 
			s=s.substr(ind+1, s.size()-ind-1); 
		}
		sum+=1LL*min_red*min_blue*min_green; 
	}
	cout<<sum<<'\n'; 

	return 0; 
}