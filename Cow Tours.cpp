/*
ID: egor_ga1
PROG: cowtour
LANG: C++11
*/
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << endl;
#define debug2(x, y) debug(x) debug(y);
#define repn(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, a) for(int i = 0; i < (int)(a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define sq(x) ((x) * (x))

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

char g[155][155];
ld d[155][155];

struct point{
	ll x, y;
};

bool cmp(point a, point b){
	if(a.x != b.x) return (a.x < b.x);
	else return (a.y < b.y);
}

bool same(point a, point b){
	return ((a.x == b.x) && (a.y == b.y));
}


ld dist(point a, point b){
	return sqrt(sq(a.x - b.x) + sq(a.y - b.y));
}

int ccw(point a, point b, point c){
	ll cur = ((c.y - a.y) * (b.x - a.x)) - ((b.y - a.y) * (c.x - a.x));
	if(!cur) return 0;
	else if(cur > 0) return 1;
	else return -1;
}

struct DSU{
	int S;
	struct node{
		int parent; ll sum;
	};
	vector<node> dsu;
	DSU(int n){
		S = n;
		rep(i, n){
			node tmp;
			tmp.parent = i; tmp.sum = 1;
			dsu.pb(tmp);
		}
	}
	void reset(int n){
		dsu.clear();
		S = n;
		rep(i, n){
			node tmp;
			tmp.parent = i; tmp.sum = 1;
			dsu.pb(tmp);
		}
	}
	int root(int u){
		if(dsu[u].parent == u) return u;
		dsu[u].parent = root(dsu[u].parent);
		return dsu[u].parent;
	}
	void merge(int u, int v){
		u = root(u); v = root(v);
		if(u == v) return;
		if(getsum(u) < getsum(v)) swap(u, v);
		dsu[v].parent = u;
		dsu[u].sum += dsu[v].sum;
	}
	bool sameset(int u, int v){
		if(root(u) == root(v)) return true;
		return false;
	}	
	ll getsum(int u){
		return dsu[root(u)].sum;
	}
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("cowtour.in", "r", stdin);
	freopen("cowtour.out", "w", stdout);
	int n;
	cin >> n;
	vector<point> p(n);
	rep(i, n){
		int a, b;
		cin >> a >> b;
		p[i] = (point){a, b};
	}
	rep(i, 155) rep(j, 155) d[i][j] = 1e14;
	rep(i, n) d[i][i] = 0;
	rep(i, n) rep(j, n){
		cin >> g[i][j];
		if(g[i][j] == '1'){
			d[i][j] = dist(p[i], p[j]);
			d[j][i] = d[i][j];
		}
	}
	ld mx2 = 0;
	rep(k, n) rep(i, n) rep(j, n){
		d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
		if(d[i][j] < 1e14) mx2 = max(mx2, d[i][j]);
	}
	DSU dsu(n);
	rep(i, n) rep(j, n) if(d[i][j] < 1e14) dsu.merge(i, j);
	vector<ld> mx1(n, 0);
	map<int, vi> m;
	rep(i, n) m[dsu.root(i)].pb(i);
	vector<ld> diam(n);
	for(pair<int, vi> x1 : m){
		vi x = x1.se;
		ld mx3 = 0;
		rep(i, x.size()){
			rep(j, x.size()) if(i != j){
				mx1[x[i]] = max(mx1[x[i]], d[x[i]][x[j]]);
				mx3 = max(mx3, d[x[i]][x[j]]);
			}
		}
		diam[x1.fi] = mx3;
	}
	ld ans = 1e14;
	rep(i, n){
		rep(j, n) if(!dsu.sameset(i, j) && g[i][j] == '0' && i != j){
				ans = min(ans, max({mx1[i] + mx1[j] + dist(p[i], p[j]), diam[dsu.root(i)], diam[dsu.root(j)]}));
		}
	}
	cout << fixed << setprecision(6) << ans << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
