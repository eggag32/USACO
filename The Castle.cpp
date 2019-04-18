/*
ID: egor_ga1
PROG: castle
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

int rn = 0;
int g[55][55];
int v[55][55];
int b[55][55];
int r[10000];

void dfs(int i, int j, int& c){
	if(v[i][j]) return;
	v[i][j] = 1;
	b[i][j] = rn;
	c++;
	if(!(g[i][j]&1)) dfs(i, j - 1, c);
	if(!(g[i][j]&2)) dfs(i - 1, j, c);
	if(!(g[i][j]&4)) dfs(i, j + 1, c);
	if(!(g[i][j]&8)) dfs(i + 1, j, c);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("castle.in", "r", stdin);
	freopen("castle.out", "w", stdout);
	int m, n;
	cin >> m >> n;
	repn(i, 1, n + 1){
		repn(j, 1, m + 1){
			cin >> g[i][j];
		}
	}
	int mx = 0;
	repn(i, 1, n + 1){
		repn(j, 1 , m + 1) if(!v[i][j]){
			int sz = 0;
			rn++;
			dfs(i, j, sz);
			r[rn] = sz;
			mx = max(mx, sz);
		}
	}
	int ip;
	int jp;
	char letter;
	int maxr = 0;
	repn(j, 1, m + 1){
		for(int i = n; i >= 1; i--){
			if(g[i][j]&2){
				if(b[i - 1][j] && b[i][j] != b[i - 1][j]){
					if((r[b[i][j]] + r[b[i - 1][j]]) > maxr){
						maxr = r[b[i][j]] + r[b[i - 1][j]]; 
						ip = i;
						jp = j;
						letter = 'N';
					}
				}
			}
			if(g[i][j]&4){
				if(b[i][j + 1] && b[i][j] != b[i][j + 1]){
					if((r[b[i][j]] + r[b[i][j + 1]]) > maxr){
						maxr = r[b[i][j]] + r[b[i][j + 1]]; 
						ip = i;
						jp = j;
						letter = 'E';
					}
				}
			}
		}
	}
	cout << rn << endl;
	cout << mx << endl;
	cout << maxr << endl;
	cout << ip << " " << jp << " " << letter << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
