/*
ID: egor_ga1
PROG: concom
LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define f first
#define s second

int st[105][105];
int c[105];
int p[105];
int n;

void dfs(int x){
	p[x] = 1;
	for(int i = 1; i <= n; i++) c[i] += st[x][i];
	for(int i = 1; i <= n; i++){
		if(c[i] >= 50 && !p[i]) dfs(i);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("concom.in", "r", stdin);
        freopen("concom.out", "w", stdout);
	cin >> n;
	int u = 0;
	for(int i = 0; i < n; i++){
		int a, b;
		cin >> a >> b;
		if(a > u) u = a;
		if(b > u) u = b;
		cin >> st[a][b];
	}
	n = u;
	for(int i = 1; i <= n; i++){
		memset(c, 0, sizeof(c));
		memset(p, 0, sizeof(p));
		dfs(i);
		for(int j = 1; j <= n; j++){
			if(i != j){
				if(p[j]) cout << i << " " << j << endl;
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
