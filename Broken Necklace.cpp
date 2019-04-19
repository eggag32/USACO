/*
ID: egor_ga1
PROG: beads 
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

int r[1000][2], l[1000][2];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("beads.in", "r", stdin);
	freopen("beads.out", "w", stdout);
	int n;
	cin >> n;
	string s;
	cin >> s;
	s = s + s;
	l[0][0] = l[0][1] = 0;
	repn(i, 1, 2 * n + 1){
		if(s[i - 1] == 'r'){
			l[i][0] = l[i - 1][0] + 1;
			l[i][1] = 0;
		}
		else if(s[i - 1] == 'b'){
			l[i][0] = 0;
			l[i][1] = l[i - 1][1] + 1;
		}
		else{
			l[i][0] = l[i - 1][0] + 1;
			l[i][1] = l[i - 1][1] + 1;
		}
        }
	r[2 * n][0] = r[2 * n][1] = 0;
	for(int i = 2 * n - 1; i >= 0; i--){
		if(s[i] == 'r'){
			r[i][0] = r[i + 1][0] + 1;
			r[i][1] = 0;
		}
		else if(s[i] == 'b'){
			r[i][1] = r[i + 1][1] + 1;
			r[i][0] = 0;
		}
		else{
			r[i][0] = r[i + 1][0] + 1;
			r[i][1] = r[i + 1][1] + 1;
		}
	} 
	int ans = 0;
	rep(i, 2 * n + 1){
		ans = max(ans, max(l[i][0], l[i][1]) + max(r[i][0], r[i][1]));
	}
	cout << min(ans, n) << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
