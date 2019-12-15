#include <bits/stdc++.h>

using namespace std;

/*
	A simple take or leave approach where you can only take when you fulfill 
	the color and the number coditions 
*/

const int M = 55;
const int N = 2e3 + 3;
bool ans = 0;
int n, s, k, t[M];
int dp[M][N][M][4];
string st;

int solve (int idx, int eaten, int last, int clr) {
	if (idx > n || idx < 0) return 2e9;
	if (eaten <= 0) {ans = 1; return 0;}
	int &ret = dp[idx][eaten][last][clr];
	if (ret != -1) return ret;
	ret = 2e9;
	if (t[idx] > last && clr != (st[idx]-'0')) {
		ret = min (ret, solve (idx-1, eaten - t[idx], t[idx], st[idx]-'0')+1);
	}
	if (t[idx] > last && clr != (st[idx]-'0')) {
		ret = min (ret, solve (idx+1, eaten - t[idx], t[idx], st[idx]-'0')+1);
	}
	ret = min (min(ret, solve (idx-1, eaten, last, clr)+1), solve (idx+1, eaten, last, clr)+1);
	return ret;
}

int main ()  {
	scanf ("%d %d %d", &n, &s, &k);
	for (int i = 0; i < n; i++) scanf ("%d", &t[i]);
	cin >> st;
	for (int i = 0; i < n; i++) {
		if (st[i] == 'R') st[i] = '0';
		if (st[i] == 'G') st[i] = '1';
		if (st[i] == 'B') st[i] = '2';
	}
	memset (dp, -1, sizeof dp);
	int x = solve (s-1, k, 0, 3);
	if (ans) printf ("%d\n", x-1);
	else puts ("-1");
}
