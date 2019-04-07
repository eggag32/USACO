/*
ID: egor_ga1
PROG: maze1
LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define repn(i, a, b) for(int i = (a); i < (b); i++)
#define rep(i, a) for(int i = 0; i < (a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl '\n'

string g[250];
int cost[250][250];
int h, w;

void dfs(int x, int y, int cnt){
	if(cost[x][y] > cnt) cost[x][y] = cnt;
	else return;
	if(x + 1 < 2 * h && g[x + 1][y] == ' ') dfs(x + 2, y, cnt + 1);
	if(x - 1 > 0 && g[x - 1][y] == ' ') dfs(x - 2, y, cnt + 1);
	if(y + 1 < 2 * w && g[x][y + 1] == ' ') dfs(x, y + 2, cnt + 1);	
	if(y - 1 > 0 && g[x][y - 1] == ' ') dfs(x, y - 2, cnt + 1);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("maze1.in", "r", stdin);
	freopen("maze1.out", "w", stdout);
	cin >> w >> h;
	rep(i, 250) rep(j, 250){
		cost[i][j] = 1e9;
	}
	getline(cin, g[0]);
	vector<pi> exit;
	rep(i, 2 * h + 1){
		getline(cin, g[i]);
	}
	rep(i, 2 * h + 1) rep(j, 2 * w + 1){
		if(i == 0 && g[i][j] == ' ') exit.pb({i + 1, j});
		if(j == 0 && g[i][j] == ' ') exit.pb({i, j + 1});
		if(i == 2 * h && g[i][j] == ' ') exit.pb({i - 1, j});
		if(j == 2 * w && g[i][j] == ' ') exit.pb({i, j - 1});
	}
	dfs(exit[0].fi, exit[0].se, 1);
	dfs(exit[1].fi, exit[1].se, 1);
	int ans = 0;
	rep(i, 2 * h + 1) rep(j, 2 * w + 1){
		if(i % 2 != 0 && j % 2 != 0 && cost[i][j] != 1e9){
			ans = max(ans, cost[i][j]);
		}
	}
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
