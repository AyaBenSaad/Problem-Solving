#include <bits/stdc++.h>

/*
	the main idea is to find when the changing process gets infinite, change based on the parity of the 
	current k and then stop the changing process
	otherwise (if there is no infinite spot)
	keep changing till the changes or the k ends
*/

using namespace std;
 
int n, k;
string s;

int main () {
	cin >> n >> k >> s;
	s = '#' + s;
	s += '#';
	for (int i = 1; i < n; i++) {
		if (k <= 0) break;
		if (i%2) {
			if (s[i] == '4' && s[i+1] == '7' && s[i+2] == '7') {
				if (k%2) s[i+1] = '4';
				break;
			}
			if (s[i] == '4' && s[i+1] == '7') {
				k--;
				s[i+1] = '4';
			}
		}
		else {
			if (s[i-1] == '4' && s[i] == '4' && s[i+1] == '7') {
				if (k%2) s[i] = '7';
				break;
			}
			if (s[i] == '4' && s[i+1] == '7') {
				k--;
				s[i] = '7';
			}
		}
	}
	for (int i = 1; i <= n; i++) cout << s[i];
	puts("");
}
