#include <bits/stdc++.h>
 
using namespace std;
 
/*
	Author : Aya Ben Saad 
	I sorted the edges by the index of the u first and the cost second
	my dp of i has two states : 
	either this node is already in the sequence so I match it with the best option
	or this node is new to the sequence so I do a take or leave
*/

const int M = 3e5 + 5;
struct edge{
    int u,v,c;
    bool operator<(const edge &r)const{
        if(u!=r.u)
            return u<r.u;
        return c<r.c;
    }
} ed[M];
 
int n, m, dp[M][2];
 
int solve(int i,bool vis){
    int &ret = dp[i][vis];
    if(ret != -1) return ret;
    ret = 0;
    if(vis) {
        edge ned;t7eb ta3mel we7ed 2e5er? wala feeling sleepy? 
        ned.u = ed[i].v;
        ned.c = ed[i].c + 1;
        int first = lower_bound(ed, ed+m, ned) - ed;
        if(first < m && ed[first].u == ned.u) ret = solve(first, 0);
    }
    else {
        ret = solve(i, 1) + 1;
        if(i + 1 < m && ed[i+1].u == ed[i].u) ret = max(ret,solve(i+1, 0));
    }
    return ret;
}
 
int main() {
    scanf ("%d %d", &n, &m);
    for(int i = 0; i < m; i++){
    	int x, y, z;
    	scanf ("%d %d %d", &x, &y, &z);
        ed[i].c = z;
        ed[i].u = x;
        ed[i].v = y;
        dp[i][0] = dp[i][1] = -1;
    }
    sort(ed, ed+m);
    int ans = 0;
    for(int i = 0; i < m; i++) ans = max (ans, solve(i, 1) + 1);
    cout << ans << endl;
}
