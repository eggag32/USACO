/*
ID: egor_ga1
PROG: ride
LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cout << #x << ": " << x << endl
#define repn(i, a, b) for(int i = (a); i < (b); i++)
#define rep(i, a) for(int i = 0; i < (a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl '\n'

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("ride.in", "r", stdin);
	freopen("ride.out", "w", stdout);
	string a, b;
	cin >> a >> b;
	int c = 1, s = 1;
	rep(i, a.size()){
		c *= a[i] - 'A' + 1;
	}
	rep(i, b.size()){
		s *= b[i] - 'A' + 1;
	}
	c %= 47;
	s %= 47;
	if(c == s) cout << "GO" << endl;
	else cout << "STAY" << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
