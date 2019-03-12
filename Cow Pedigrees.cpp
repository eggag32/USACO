/*
ID: egor_ga1
PROG: nocows
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
const int MOD = 9901;

int dp[205][105];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("nocows.in", "r", stdin);
        freopen("nocows.out", "w", stdout);
	int n, d;
	cin >> n >> d;
	memset(dp, 0, sizeof(dp));
	for(int i = 1; i <= d; i++) dp[1][i] = 1;
	for(int i = 3; i <= n; i += 2){
		for(int j = 2; j <= d; j++){
			for(int a = 1; a < (i - 1); a += 2){
				dp[i][j] += dp[a][j - 1] * dp[i - a - 1][j - 1];
				dp[i][j] %= MOD;
			}
		}
	}
	cout << (dp[n][d] - dp[n][d - 1] + MOD) % MOD << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
