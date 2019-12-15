#include <bits/stdc++.h>

using namespace std;

/*
	precompute a suffix min 
	and for each position binary search to find the farthest element less than the current element
*/

const int M = 1e5 + 5;
int n, a[M], ans[M];
pair <int, int> suff[M];

int main () {
	scanf ("%d", &n);
	suff [n] = {2e9, n};
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	for (int i = n-1; i >= 0; i--) {
		if (a[i] < suff[i+1].first)suff[i] = {a[i], i};
		else if (a[i] == suff[i+1].first)suff[i] = {a[i], i};
		else suff[i] = suff[i+1];
	} 
	for (int i = 0; i < n; i++) {
		int l = i, r = n-1;
		while (l < r) {
			int mid = (l+r+1)/2;
			if (suff[mid].first < a[i]) l =mid;
			else r = mid-1;
		}
		cout << suff[l].second - i - 1 << ' ';
	}
	puts ("");
}
