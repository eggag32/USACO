/*
ID: egor_ga1
PROG: holstein
LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define all(v) v.begin(),v.end() 
#define mp make_pair
#define pb push_back
#define f first
#define s second

int n, g;
int mn;
int need[26];
int feed[16][26];
int v[26];
int ans[16];
int res[16];

bool check(){
	bool x = true;
	for(int i = 1; i <= n; i++){
		if(v[i] < need[i]){
			x = false;
		}
	}
	return x;
}

void dfs(int d, int c){
	if(d == g + 1){
		if(!check()){
			return;
		}
		if(c < mn){
			mn = c;
			for(int i = 1; i <= mn; i++){
				ans[i] = res[i];
			}
		}
		return;
	}
	for(int i = 1; i <= n; i++){
		v[i] += feed[d][i];
	}
	res[c + 1] = d;
	dfs(d + 1, c + 1);
	for(int i = 1; i <= n; i++){
		v[i] -= feed[d][i];
	}
	dfs(d + 1, c);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("holstein.in", "r", stdin);
        freopen("holstein.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> need[i];
	}
	cin >> g;
	for(int i = 1; i <= g; i++){
		for(int j = 1; j <= n; j++){
			cin >> feed[i][j];
		}
	}
	mn = INT_MAX;
	dfs(1, 0);
	cout << mn;
	for(int i = 1; i <= mn; i++){
		cout << " " << ans[i];
	}
	cout << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
*/
