/*
ID: egor_ga1
PROG: comehome
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
#define debug(x) cerr << #x << ": " << x << endl
#define debug2(x, y) debug(x), debug(y);
#define repn(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, a) for(int i = 0; i < (int)(a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl '\n'

int gcd(int a, int b){ return ((b == 0) ? a : gcd(b, a % b)); }

vector<pi> g[1005];
ll dist[1005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("comehome.in", "r", stdin);
	freopen("comehome.out", "w", stdout);
	int n;
	cin >> n;
	rep(i, n){
		char a, b;
		int c;
		cin >> a >> b >> c;
		g[(int)a].pb({(int)b, c});
		g[(int)b].pb({(int)a, c});
	}
	rep(i, 1005) dist[i] = 1e18;
	dist[(int)'Z'] = 0;
	set<pair<ll, int>> q;
	q.insert({0, (int)'Z'});
	while(q.size()){
		ll p = q.begin() -> fi;
		int cur = q.begin() -> se;
		q.erase(q.begin());
		if(cur >= 'A' && cur < 'Z'){
			cout << (char)cur << " " << p << endl;
			return 0;
		}
		for(auto x : g[cur]){
			if(dist[x.fi] > (dist[cur] + x.se)){
				q.erase({dist[x.fi], x.fi});
				dist[x.fi] = dist[cur] + x.se;
				q.insert({dist[x.fi], x.fi});
			}
		}
	}
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
