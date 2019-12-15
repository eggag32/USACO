/*
ID: egor_ga1
PROG: inflate
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

int dp[10005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("inflate.in", "r", stdin);
	freopen("inflate.out", "w", stdout);
	int n, m;
	cin >> m >> n;
	vi a(n), b(n);
	rep(i, n) cin >> a[i] >> b[i];
	memset(dp, 0, sizeof(dp));
	rep(i, n){
		for(int j = 0; (j + b[i]) <= m; j++){
			dp[j + b[i]] = max(dp[j + b[i]], dp[j] + a[i]);
		}
	}
	int ans = 0;
	rep(i, m + 1) ans = max(ans, dp[i]);
	cout << ans << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
