#include <bits/stdc++.h>
 
using namespace std;

/*
	try all combinations for the first string a and value b which are n choose b
	for every string check if it is not contradicting with other attemps if yes increment the ans
*/

int n, m, k;
string a[12];
int b[12], vis[40];
vector <string> v;

void solve(int i, int rem){
    if(i == k + 1){
    	if (rem == 0) {
	    	string s = "";
	        for(int j=1; j<=k; j++){
	        	if(vis[j]) s += a[0][j];
	        	else s += (a[0][j] == '0' ? '1' : '0');
	        }
	        //cout << s << endl;
	        v.push_back(s);
	    }
        return;
    }
 
    if(rem > 0){
        vis[i] = 1;
        solve(i + 1, rem - 1);
        vis[i] = 0;
    }
 
    if(k - i + 1 > rem)
        solve(i + 1, rem);
}

bool ok (string s) {
	//cout << s << endl;
	for (int i = 0; i < m; i++) {
		int k = 0;
		for (int j = 0; j < n; j++) {
			if (s[j] == a[i][j]) k++;
		}
		//cout << k << ' ';
		if (k != b[i]) {return 0;}
	}
	return 1;
}

int main () {
	cin >> n >> m;
	for (int i = 0; i < m; i++) cin >> a[i] >> b[i];
	k = b[0];
	string g = a[0];
	a[0] = 'x'+a[0];
	swap (k, n);
	solve (1, n);
	swap (k, n);
	int ans = 0;
	a[0] = g;
	for (auto s : v) {
		if (ok (s)) ans++;
	}
	cout << ans << endl;
}
