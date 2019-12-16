#include <bits/stdc++.h>

using namespace std;

/*
 Just I needed to brute force over the possible results and try the new ranking with each one
*/

string a[10], b[10];
int x[10], y[10], ans = 2e9, ans1 = 9, ans2 = 9;
map <string, int> scored, missed, score, mention;
vector <string> v;
set <pair <pair <int, int>, pair <int, string> > > st;

bool ok () {
	auto a = *st.begin();
	st.erase(st.begin());
	auto b = *st.begin();
	st.insert(a);
	//cout << a.second.second << ' ' << b.second.second << endl;
	if (a.second.second == "BERLAND") return 1;
	if (b.second.second == "BERLAND") return 1;
	return 0; 
}

int main () {
	for (int i = 0; i < 5; i++) {
		string s;
		cin >> a[i] >> b[i] >> s;
		y[i] = s[s.size()-1]-'0';
		x[i] = s[s.size()-3]-'0';
		scored[a[i]] += x[i];
		scored[b[i]] += y[i];
		missed[a[i]] += y[i];
		missed[b[i]] += x[i];
		if (x[i] > y[i]) score[a[i]] += 3;
		if (x[i] < y[i]) score[b[i]] += 3;
		if (x[i] == y[i]) {score[a[i]] += 1; score[b[i]] += 1;}
		mention[a[i]]++;
		mention[b[i]]++;

	}
	for (auto i : mention) {
		if (i.second < 3) v.push_back (i.first);
	}
	for (int i = 0; i < 5; i++) {
		if (mention[b[i]] >= 3) st.insert({{-score[b[i]], missed[b[i]]-scored[b[i]]}, {-scored[b[i]], b[i]}});
		swap (b[i], a[i]);
		if (mention[b[i]] >= 3) st.insert({{-score[b[i]], missed[b[i]]-scored[b[i]]}, {-scored[b[i]], b[i]}});
	}
	string d = v[0], f = v[1];
	if (f == "BERLAND") swap (f, d);
	//ok();
	for (int j = 0; j <= 250; j++) {
		for (int i = j+1; i <= 250; i++) {
			scored[d] += i;
			scored[f] += j;
			missed[d] += j;
			missed[f] += i;
			score[d] += 3;

			st.insert({{-score[d], missed[d]-scored[d]}, {-scored[d], d}});
			st.insert({{-score[f], missed[f]-scored[f]}, {-scored[f], f}});

			if (ok() && ans > i-j) {ans = i-j; ans1 = i; ans2 = j;} 

			st.erase(st.find({{-score[d], missed[d]-scored[d]}, {-scored[d], d}}));
			st.erase(st.find({{-score[f], missed[f]-scored[f]}, {-scored[f], f}}));

			scored[d] -= i;
			scored[f] -= j;
			missed[d] -= j;
			missed[f] -= i;
			score[d] -= 3;
		}
	}
	if (ans1 != ans2) cout << ans1 << ":" << ans2 << endl;
	else puts ("IMPOSSIBLE");
}
