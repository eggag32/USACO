/*
ID: egor_ga1
PROG: money
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

int c[30];
ll dp[10005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("money.in", "r", stdin);
        freopen("money.out", "w", stdout);
	int v, n;
	cin >> v >> n;
	for(int i = 0; i < v; i++){
		cin >> c[i];
	}
	dp[0] = 1;
	for(int i = 0; i < v; i++){
		for(int j = c[i]; j <= n; j++){
			dp[j] += dp[j - c[i]];
		}
	}
	cout << dp[n] << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
