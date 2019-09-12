#include <bits/stdc++.h>

using namespace std;

/*
	Author : Aya Ben Saad
	try all options in ascending order
	but we don't try them literally, we do a simplification
	let's take (z^x)^y as an example
	z is in the base, let's pose c = log(z)
	(z^x)^y = ((10^c)^x)^y = 10^(c*y*z)
	so we just need to maximize the product of log base and the power
*/
 
long double x, y, z, mx, ans;
map <int, string> mp;

int main() {
	mp[11] = "(z^x)^y";
	mp[10] = "z^y^x"; mp[9] = "z^x^y";
	mp[7] = "(y^x)^z"; mp[6] = "y^z^x";
	mp[5] = "y^x^z"; mp[3] = "(x^y)^z";
	mp[2] = "x^z^y"; mp[1] = "x^y^z";
	cin >> x >> y >> z;
	long double a = log(x);
	long double b = log(y);
	long double c = log(z);
	mx = x*y*c;
	ans = 11;
	if (pow(y,x)*c >= mx) mx = pow(y,x)*c, ans = 10;
	if (pow(x,y)*c >= mx) mx = pow(x,y)*c, ans = 9;
	if (x*z*b >= mx) mx = x*z*b, ans = 7;
	if (pow(z,x)*b >= mx) mx = pow(z,x)*b, ans = 6;
	if (pow(x,z)*b >= mx) mx = pow(x,z)*b, ans = 5;
	if (y*z*a >= mx) mx = y*z*a, ans = 3;
	if (pow(z,y)*a >= mx) mx = pow(z,y)*a, ans = 2;
	if (pow(y,z)*a >= mx) mx = pow(y,z)*a, ans = 1;
	cout << mp[ans] << endl;
}
