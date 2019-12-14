#include <bits/stdc++.h>
/*
	brute force on digits from 0 to 9 and for each one find the min cost and the min lexografical string
	so i sorted the in a way where to choose the top k positions where 
	the cost change is minimal and I keep the lexografical condition valid
	so I made three conditions for my sorting
		1) the changing cost
		2) a parametere to see if the original value is bigger& or not
		3) the position with the 2nd parametre deciding its sign

*/ 
using namespace std;
 
const int M = 1e4 + 4;
int n, k, cost = 2e9; 
string s, ans;

pair <int, string> solve (int x) {
	int ret = 0;
	string t = s;
	set <pair <pair<int,bool>, int> > st;
	for (int i = 0; i < n; i++) st.insert ({{abs((s[i]-'0')-x), x > (s[i]-'0')}, i * ((x > (s[i]-'0')) ? -1 : 1)});
	for (int i = 0; i < k; i++) {
		auto p = *st.begin();
		st.erase(st.begin());
		ret += p.first.first;
		t[abs(p.second)] = x+'0';
	}
	return make_pair(ret, t);
}

int main () {
	scanf("%d %d", &n, &k);
	cin >> s;
	for (int i = 0; i < n; i++) ans += '9';
	for (int i = 0; i < 10; i++) {
		auto p = solve (i);
		if (cost == p.first) {
			if (p.second < ans) ans = p.second;
		}
		if (cost > p.first) {
			cost = p.first;
			ans = p.second;
		}
	}
	cout << cost << endl << ans << endl;
}
