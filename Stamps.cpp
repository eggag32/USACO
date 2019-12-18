/*
ID: egor_ga1
PROG: stamps
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

pair<bool, int> dp[20005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("stamps.in", "r", stdin);
	freopen("stamps.out", "w", stdout);
	int k, n;
	cin >> k >> n;
	vi a(n);
	rep(i, n) cin >> a[i];
	dp[0] = {1, 0};
	int it = 0;
	//we only need the last some (10000?)
	repn(i1, 1, 2000005){
		int i = i1 % 20005;
		dp[i] = {0, 1e9};
		if(!i) it++;
		rep(j, n) if(i >= a[j] || (it && i < a[j])){
			int nw = i - a[j];
			if(nw < 0){
				assert(it);
				nw = (20005 - (a[j] - i));
			}
			if((dp[nw].fi && dp[nw].se) < k){
				dp[i].fi |= dp[nw].fi;
				dp[i].se = min(1 + dp[nw].se, dp[i].se);
			}
		}
		if(!dp[i].fi || dp[i].se > k){
			cout << i1 - 1 << endl;
			return 0;
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
