#include <bits/stdc++.h>
using namespace std; 

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	string s1,s2;
	cin >> s1;
	cin >> s2;

	int cnt = 0;
	vector<char> st;

	for(int i = 0; i < s1.size(); i++){
		st.push_back(s1[i]);

		if(!st.empty()){
			if(st.back() == s2[cnt]) cnt++;			
		}
		if(cnt == s2.size()) {
			while(cnt--) st.pop_back();
		}		
	}
		
	if(st.empty()){
		cout << "FRULA";
	}
	else{
		for(auto c: st) cout << c;
	}

	
	return 0;
}