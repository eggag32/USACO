/*
ID: egor_ga1
PROG: agrinet
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

int d[105][105];
int intree[105];
int dist[105];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("agrinet.in", "r", stdin);
	freopen("agrinet.out", "w", stdout);
	int n;
	cin >> n;
	rep(i, n) rep(j, n) cin >> d[i][j];
	memset(intree, 0, sizeof(intree));
	rep(i, 105) dist[i] = 1e9;
	intree[0] = 1;
	int tsize = 1;
	int tcost = 0;
	int prev = 0;
	while(tsize < n){
		rep(i, n) if(!intree[i]){
			if(dist[i] > d[prev][i]) dist[i] = d[prev][i];
		}
		int mn = 1e9;
		int b = -1;
		rep(i, n) if(!intree[i]){
			if(dist[i] < mn){
				mn = dist[i];
				b = i;
			}
		}
		tsize++;
		tcost += mn;
		intree[b] = 1;
		prev = b;
	}
	cout << tcost << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
